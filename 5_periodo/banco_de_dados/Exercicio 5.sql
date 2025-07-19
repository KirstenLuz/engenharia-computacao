
-- M3 Atividade em Sala 02 - IMPLEMENTAÇÃO COMPLETA

-- CRIAÇÃO DO ESQUEMA
CREATE DATABASE IF NOT EXISTS biblioteca;
USE biblioteca;

-- TABELAS PRINCIPAIS

-- Criação da tabela Livros
CREATE TABLE IF NOT EXISTS Livros (
    id_livro INT PRIMARY KEY AUTO_INCREMENT,
    titulo VARCHAR(255) NOT NULL,
    autor VARCHAR(255) NOT NULL,
    ano_publicacao INT,
    disponivel BOOLEAN DEFAULT TRUE
);

-- Criação da tabela Membros
CREATE TABLE IF NOT EXISTS Membros (
    id_membro INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL UNIQUE,
    data_cadastro DATE NOT NULL
);

-- Criação da tabela Empréstimos
CREATE TABLE IF NOT EXISTS Emprestimos (
    id_emprestimo INT PRIMARY KEY AUTO_INCREMENT,
    id_livro INT NOT NULL,
    id_membro INT NOT NULL,
    data_emprestimo DATE NOT NULL,
    data_devolucao DATE,
    FOREIGN KEY (id_livro) REFERENCES Livros(id_livro),
    FOREIGN KEY (id_membro) REFERENCES Membros(id_membro)
);

-- TABELAS AUXILIARES

-- Tabela de auditoria de empréstimos
CREATE TABLE IF NOT EXISTS AuditoriaEmprestimos (
    id_auditoria INT PRIMARY KEY AUTO_INCREMENT,
    id_emprestimo INT NOT NULL,
    data_emprestimo DATE NOT NULL,
    acao VARCHAR(255) NOT NULL,
    usuario VARCHAR(255)
);

-- Tabela de histórico de alterações de livros
CREATE TABLE IF NOT EXISTS HistoricoLivros (
    id_historico INT PRIMARY KEY AUTO_INCREMENT,
    id_livro INT NOT NULL,
    titulo_antigo VARCHAR(255),
    autor_antigo VARCHAR(255),
    ano_publicacao_antigo INT,
    data_alteracao TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Tabela de auditoria de ações em livros
CREATE TABLE IF NOT EXISTS AuditoriaLivros (
    id_audit_livro INT PRIMARY KEY AUTO_INCREMENT,
    currentuser TEXT,
    operacao CHAR(1),
    titulo VARCHAR(255),
    autor VARCHAR(255),
    data_operacao TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- DADOS DE TESTE

-- Inserção de dados na tabela Livros
INSERT INTO Livros (titulo, autor, ano_publicacao) VALUES
('Dom Quixote', 'Miguel de Cervantes', 1605),
('O Pequeno Príncipe', 'Antoine de Saint-Exupéry', 1943),
('Hamlet', 'William Shakespeare', 1603),
('Cem Anos de Solidão', 'Gabriel Garcia Márquez', 1967),
('Orgulho e Preconceito', 'Jane Austen', 1813),
('1984', 'George Orwell', 1949),
('O Senhor dos Anéis', 'J.R.R. Tolkien', 1954),
('A Divina Comédia', 'Dante Alighieri', 1320);

-- Inserção de dados na tabela Membros
INSERT INTO Membros (nome, email, data_cadastro) VALUES
('Ana Silva', 'ana.silva@example.com', '2022-01-10'),
('Bruno Gomes', 'bruno.gomes@example.com', '2022-02-15'),
('Carlos Eduardo', 'carlos.eduardo@example.com', '2022-03-20'),
('Daniela Rocha', 'daniela.rocha@example.com', '2022-05-05'),
('Eduardo Lima', 'eduardo.lima@example.com', '2022-06-10'),
('Fernanda Martins', 'fernanda.martins@example.com', '2022-07-15'),
('Gustavo Henrique', 'gustavo.henrique@example.com', '2022-08-20'),
('Helena Souza', 'helena.souza@example.com', '2022-09-25');

-- Inserção de dados na tabela Empréstimos
INSERT INTO Emprestimos (id_livro, id_membro, data_emprestimo, data_devolucao) VALUES
(1, 1, '2022-04-01', NULL),
(2, 2, '2022-04-03', '2022-04-10'),
(3, 3, '2022-04-05', NULL),
(4, 4, '2022-10-01', NULL),
(5, 5, '2022-10-03', '2022-10-17'),
(2, 3, '2022-10-06', NULL),
(1, 2, '2022-10-08', '2022-10-15'),
(3, 1, '2022-10-10', NULL),
(3, 2, '2022-11-01', NULL),
(2, 3, '2022-11-03', NULL),
(1, 4, '2022-11-05', NULL),
(5, 1, '2022-11-07', '2022-11-21'),
(4, 5, '2022-11-09', '2022-11-23'),
(2, 1, '2022-11-12', NULL),
(3, 4, '2022-11-14', '2022-11-28'),
(1, 3, '2022-11-16', NULL),
(5, 2, '2022-11-18', '2022-11-25'),
(4, 1, '2022-11-20', '2022-12-04');

-- TRIGGERS

-- (Mesma sequência da versão anterior)


-- M3 Atividade em Sala 02 - IMPLEMENTAÇÃO DAS TRIGGERS

-- A. Trigger de Atualização de Disponibilidade
DELIMITER $$
CREATE TRIGGER trg_atualizar_disponibilidade_false
AFTER INSERT ON Emprestimos
FOR EACH ROW
BEGIN
    UPDATE Livros SET disponivel = FALSE WHERE id_livro = NEW.id_livro;
END$$
DELIMITER ;

-- B. Trigger de Devolução de Livro
DELIMITER $$
CREATE TRIGGER trg_devolucao_livro
AFTER UPDATE ON Emprestimos
FOR EACH ROW
BEGIN
    IF NEW.data_devolucao IS NOT NULL AND OLD.data_devolucao IS NULL THEN
        UPDATE Livros SET disponivel = TRUE WHERE id_livro = NEW.id_livro;
    END IF;
END$$
DELIMITER ;

-- C. Trigger de Auditoria de Empréstimos
ALTER TABLE AuditoriaEmprestimos ADD COLUMN usuario VARCHAR(255);

DELIMITER $$
CREATE TRIGGER trg_auditoria_emprestimo
AFTER INSERT ON Emprestimos
FOR EACH ROW
BEGIN
    INSERT INTO AuditoriaEmprestimos (id_emprestimo, data_emprestimo, acao, usuario)
    VALUES (NEW.id_emprestimo, NEW.data_emprestimo, 'Empréstimo Realizado', CURRENT_USER());
END$$
DELIMITER ;

-- D. Trigger de Verificação de Disponibilidade
DELIMITER $$
CREATE TRIGGER trg_verificar_disponibilidade
BEFORE INSERT ON Emprestimos
FOR EACH ROW
BEGIN
    DECLARE disp BOOLEAN;
    DECLARE titulo_livro VARCHAR(255);

    SELECT disponivel, titulo INTO disp, titulo FROM Livros WHERE id_livro = NEW.id_livro;

    IF disp = FALSE THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = CONCAT('O livro ', titulo_livro, ' está indisponível para empréstimo.');
    END IF;
END$$
DELIMITER ;

-- E. Trigger de Limite de Empréstimos
DELIMITER $$
CREATE TRIGGER trg_limite_emprestimos
BEFORE INSERT ON Emprestimos
FOR EACH ROW
BEGIN
    DECLARE qtd INT;

    SELECT COUNT(*) INTO qtd
    FROM Emprestimos
    WHERE id_membro = NEW.id_membro AND data_devolucao IS NULL;

    IF qtd >= 5 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'O membro já possui 5 empréstimos em aberto.';
    END IF;
END$$
DELIMITER ;

-- F. Trigger de Atualização de Livros
DELIMITER $$
CREATE TRIGGER trg_historico_livros
BEFORE UPDATE ON Livros
FOR EACH ROW
BEGIN
    INSERT INTO HistoricoLivros (id_livro, titulo_antigo, autor_antigo, ano_publicacao_antigo)
    VALUES (OLD.id_livro, OLD.titulo, OLD.autor, OLD.ano_publicacao);
END$$
DELIMITER ;

-- G. Trigger de Exclusão de Membro
DELIMITER $$
CREATE TRIGGER trg_exclusao_membro
BEFORE DELETE ON Membros
FOR EACH ROW
BEGIN
    DECLARE qtd INT;

    SELECT COUNT(*) INTO qtd
    FROM Emprestimos
    WHERE id_membro = OLD.id_membro AND data_devolucao IS NULL;

    IF qtd > 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = CONCAT('Não é possível excluir o membro ', OLD.nome, ', pois possui empréstimos pendentes.');
    END IF;
END$$
DELIMITER ;

-- H. Trigger de Auditoria para Livros
DELIMITER $$
CREATE TRIGGER trg_auditoria_livros_insert
AFTER INSERT ON Livros
FOR EACH ROW
BEGIN
    INSERT INTO AuditoriaLivros (currentuser, operacao, titulo, autor)
    VALUES (CURRENT_USER(), 'I', NEW.titulo, NEW.autor);
END$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER trg_auditoria_livros_update
AFTER UPDATE ON Livros
FOR EACH ROW
BEGIN
    INSERT INTO AuditoriaLivros (currentuser, operacao, titulo, autor)
    VALUES (CURRENT_USER(), 'U', NEW.titulo, NEW.autor);
END$$
DELIMITER ;

DELIMITER $$
CREATE TRIGGER trg_auditoria_livros_delete
AFTER DELETE ON Livros
FOR EACH ROW
BEGIN
    INSERT INTO AuditoriaLivros (currentuser, operacao, titulo, autor)
    VALUES (CURRENT_USER(), 'D', OLD.titulo, OLD.autor);
END$$
DELIMITER ;

-- I. Trigger para impedir exclusão de livros emprestados
DELIMITER $$
CREATE TRIGGER trg_impedir_exclusao_livros
BEFORE DELETE ON Livros
FOR EACH ROW
BEGIN
    DECLARE qtd INT;

    SELECT COUNT(*) INTO qtd
    FROM Emprestimos
    WHERE id_livro = OLD.id_livro AND data_devolucao IS NULL;

    IF qtd > 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = CONCAT('Não é possível excluir o livro ', OLD.titulo, ', pois está atualmente emprestado.');
    END IF;
END$$
DELIMITER ;
