/* 
Kirsten Luz Concepcion e Isabella Zermiani Bastos
*/

DROP SCHEMA IF EXISTS midias_antigas;
-- Remove o schema, se existir

CREATE SCHEMA midias_antigas;
-- Cria o novo schema

USE midias_antigas;
-- Seleciona o schema para uso

-- Tabela de clientes
CREATE TABLE cliente (
	id INT PRIMARY KEY AUTO_INCREMENT,
    cpf VARCHAR(14) UNIQUE NOT NULL,
    nome VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE,
    telefone VARCHAR(25) NOT NULL,
    cadastrado_em TIMESTAMP NOT NULL
);

-- Tabela de atores
CREATE TABLE ator (
	id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    nome_artistico VARCHAR(100) NOT NULL,
    data_nascimento DATE NOT NULL
);

-- Tabela de empréstimos
CREATE TABLE emprestimo (
	id INT PRIMARY KEY AUTO_INCREMENT,
    id_cliente INT NOT NULL,
    realizado_em TIMESTAMP NOT NULL,
    FOREIGN KEY (id_cliente) REFERENCES cliente (id)
);

-- Tabela de categorias de filmes
CREATE TABLE categoria (
	id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL
);

-- Tabela de filmes
CREATE TABLE filme (
	id INT PRIMARY KEY AUTO_INCREMENT,
    titulo VARCHAR(100) NOT NULL,
    ano YEAR NOT NULL,
    id_categoria INT NOT NULL,
    cadastrado_em TIMESTAMP NOT NULL,
    disponivel BOOLEAN NOT NULL,
    FOREIGN KEY (id_categoria) REFERENCES categoria (id)
);

-- Tabela de itens emprestados
CREATE TABLE item_emprestimo (
    id_emprestimo INT NOT NULL,
    id_filme INT NOT NULL,
    FOREIGN KEY (id_emprestimo) REFERENCES emprestimo (id),
    FOREIGN KEY (id_filme) REFERENCES filme (id)
);

-- Relação entre filmes e atores
CREATE TABLE estrela (
    id_filme INT NOT NULL,
    id_ator INT NOT NULL,
    FOREIGN KEY (id_filme) REFERENCES filme (id),
    FOREIGN KEY (id_ator) REFERENCES ator (id)
);

-- Inserção de dados de clientes
INSERT INTO cliente (cpf, nome, email, telefone, cadastrado_em) VALUES
('123.456.789-01', 'Isabela Moreira', 'isa.moreira@gmail.com', '+55 (47) 98888-1111', NOW()),
('987.654.321-02', 'Vinícius Andrade', 'vinicius.andrade@gmail.com', '+55 (47) 97777-2222', NOW()),
('456.789.123-03', 'Patrícia Fernandes', 'pat.fernandes@gmail.com', '+55 (47) 96666-3333', NOW());

-- Inserção de atores
INSERT INTO ator (nome, nome_artistico, data_nascimento) VALUES
('Margot Robbie', 'Barbie', '1990-07-02'),
('Ryan Gosling', 'Ken', '1980-11-12'),
('America Ferrera', 'Gloria', '1984-04-18'),
('Will Ferrell', 'CEO da Mattel', '1967-07-16');

-- Inserção de categorias
INSERT INTO categoria (nome) VALUES
('Aventura'),
('Fantasia'),
('Família'),
('Musical'),
('Animação');

-- Inserção de filmes da Barbie
INSERT INTO filme (titulo, ano, id_categoria, cadastrado_em, disponivel) VALUES
('Barbie e o Castelo de Diamante', 2008, 4, NOW(), TRUE),
('Barbie como Rapunzel', 2002, 2, NOW(), FALSE),
('Barbie Fairytopia', 2005, 2, NOW(), TRUE),
('Barbie e o Quebra-Nozes', 2001, 5, NOW(), TRUE),
('Barbie', 2023, 1, NOW(), FALSE);

-- Estrelando nos filmes
INSERT INTO estrela (id_filme, id_ator) VALUES
(1, 1), -- Castelo de Diamante com Barbie
(2, 1), -- Rapunzel com Barbie
(3, 1), -- Fairytopia com Barbie
(4, 1), -- Quebra-Nozes com Barbie
(5, 1), -- Barbie (2023) com Margot
(5, 2), -- Barbie (2023) com Ken
(5, 3), -- Barbie (2023) com Gloria
(5, 4); -- Barbie (2023) com CEO da Mattel

-- Empréstimos realizados
INSERT INTO emprestimo (id_cliente, realizado_em) VALUES
(1, NOW()),
(2, NOW()),
(3, NOW());

-- Itens emprestados
INSERT INTO item_emprestimo (id_emprestimo, id_filme) VALUES
(1, 2), -- Isabela pegou "Rapunzel"
(2, 5), -- Vinícius pegou "Barbie (2023)"
(3, 4), -- Patrícia pegou "Quebra-Nozes"
(3, 1); -- Patrícia também pegou "Castelo de Diamante"
