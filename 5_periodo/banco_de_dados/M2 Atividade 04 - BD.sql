-- 1. Inserir novo endereço
DELIMITER //
CREATE PROCEDURE inserirEndereco (
    IN p_logradouro VARCHAR(100),
    IN p_numero INT,
    IN p_complemento VARCHAR(50),
    IN p_cep VARCHAR(12),
    IN p_cidade VARCHAR(50),
    IN p_uf VARCHAR(2)
)
BEGIN
    INSERT INTO Endereco (logradouro, numero, complemento, cep, cidade, uf)
    VALUES (p_logradouro, p_numero, p_complemento, p_cep, p_cidade, p_uf);
END;
//
DELIMITER ;

-- 2. Atualizar email de um responsável
DELIMITER //
CREATE PROCEDURE atualizarEmailResponsavel (
    IN p_cod INT,
    IN p_novo_email VARCHAR(100)
)
BEGIN
    UPDATE Responsavel SET email = p_novo_email WHERE cod = p_cod;
END;
//
DELIMITER ;

-- 4. Excluir um responsável e seus pets e endereço
DELIMITER //
CREATE PROCEDURE excluirResponsavel (
    IN p_cod INT
)
BEGIN
    DECLARE v_end INT;
    SELECT cod_end INTO v_end FROM Responsavel WHERE cod = p_cod;
    DELETE FROM Pet WHERE cod_resp = p_cod;
    DELETE FROM Responsavel WHERE cod = p_cod;
    IF NOT EXISTS (SELECT 1 FROM Responsavel WHERE cod_end = v_end) THEN
        DELETE FROM Endereco WHERE cod = v_end;
    END IF;
END;
//
DELIMITER ;

-- 5. Listar consultas agendadas por data
DELIMITER //
CREATE PROCEDURE listarConsultasPorData (
    IN p_data DATE
)
BEGIN
    SELECT 
        c.dt AS data_consulta,
        r.nome AS nome_responsavel,
        p.nome AS nome_pet,
        r.fone AS telefone_responsavel,
        v.nome AS nome_veterinario
    FROM Consulta c
    JOIN Pet p ON c.cod_pet = p.cod
    JOIN Responsavel r ON p.cod_resp = r.cod
    JOIN Veterinario v ON c.cod_vet = v.cod
    WHERE c.dt = p_data;
END;
//
DELIMITER ;

-- 6. Inserir novo veterinário e retornar todos
DELIMITER //
CREATE PROCEDURE inserirVeterinario (
    IN p_nome VARCHAR(100),
    IN p_crmv NUMERIC(10),
    IN p_especialidade VARCHAR(50),
    IN p_email VARCHAR(100),
    IN p_fone VARCHAR(50),
    IN p_cod_end INT
)
BEGIN
    INSERT INTO Veterinario (nome, crmv, especialidade, email, fone, cod_end)
    VALUES (p_nome, p_crmv, p_especialidade, p_email, p_fone, p_cod_end);

    SELECT * FROM Veterinario;
END;
//
DELIMITER ;

-- 7. Adicionar novo pet
DELIMITER //
CREATE PROCEDURE adicionarPet (
    IN p_nome VARCHAR(100),
    IN p_raca VARCHAR(50),
    IN p_peso DECIMAL(5,2),
    IN p_data_nasc DATE,
    IN p_cod_resp INT
)
BEGIN
    INSERT INTO Pet (nome, raca, peso, data_nasc, cod_resp)
    VALUES (p_nome, p_raca, p_peso, p_data_nasc, p_cod_resp);
END;
//
DELIMITER ;

-- 8. Contar pets de um responsável
DELIMITER //
CREATE PROCEDURE contarPetsPorResponsavel (
    IN p_cod_resp INT
)
BEGIN
    SELECT COUNT(*) AS total_pets FROM Pet WHERE cod_resp = p_cod_resp;
END;
//
DELIMITER ;

-- 9. Listar veterinários por especialidade
DELIMITER //
CREATE PROCEDURE listarVetsPorEspecialidade (
    IN p_especialidade VARCHAR(50)
)
BEGIN
    SELECT * FROM Veterinario WHERE especialidade = p_especialidade;
END;
//
DELIMITER ;

-- 10. Atualizar endereço de um veterinário
DELIMITER //
CREATE PROCEDURE atualizarEnderecoVeterinario (
    IN p_cod_vet INT,
    IN p_novo_cod_end INT
)
BEGIN
    UPDATE Veterinario SET cod_end = p_novo_cod_end WHERE cod = p_cod_vet;
END;
//
DELIMITER ;

-- 11. Calcular idade de um pet
DELIMITER //
CREATE PROCEDURE idadePet (
    IN p_cod_pet INT
)
BEGIN
    SELECT nome, TIMESTAMPDIFF(YEAR, data_nasc, CURDATE()) AS idade
    FROM Pet
    WHERE cod = p_cod_pet;
END;
//
DELIMITER ;

-- 12. Endereços por cidade
DELIMITER //
CREATE PROCEDURE listarEnderecosPorCidade (
    IN p_cidade VARCHAR(50)
)
BEGIN
    SELECT * FROM Endereco WHERE cidade = p_cidade;
END;
//
DELIMITER ;

-- 13. Associar pet a novo responsável
DELIMITER //
CREATE PROCEDURE associarNovoResponsavel (
    IN p_cod_pet INT,
    IN p_novo_cod_resp INT
)
BEGIN
    UPDATE Pet SET cod_resp = p_novo_cod_resp WHERE cod = p_cod_pet;
END;
//
DELIMITER ;

-- 14. Consultas de um veterinário
DELIMITER //
CREATE PROCEDURE consultasPorVeterinario (
    IN p_cod_vet INT
)
BEGIN
    SELECT 
        c.dt AS data_consulta,
        c.horario,
        p.nome AS nome_pet,
        r.nome AS nome_responsavel
    FROM Consulta c
    JOIN Pet p ON c.cod_pet = p.cod
    JOIN Responsavel r ON p.cod_resp = r.cod
    WHERE c.cod_vet = p_cod_vet;
END;
//
DELIMITER ;

-- 15. Buscar nome do responsável pelo nome do pet
DELIMITER //
CREATE PROCEDURE buscarResponsavelPorPet (
    IN p_nome_pet VARCHAR(100)
)
BEGIN
    SELECT r.nome AS nome_responsavel
    FROM Pet p
    JOIN Responsavel r ON p.cod_resp = r.cod
    WHERE p.nome = p_nome_pet;
END;
//
DELIMITER ;

-- 16. Buscar responsável por CPF
DELIMITER //
CREATE PROCEDURE buscarResponsavelPorCPF (
    IN p_cpf VARCHAR(12)
)
BEGIN
    DECLARE v_nome VARCHAR(100);

    SELECT nome INTO v_nome FROM Responsavel WHERE cpf = p_cpf;

    IF v_nome IS NOT NULL THEN
        SELECT v_nome AS nome_responsavel;
    ELSE
        SELECT 'Responsável não encontrado' AS mensagem;
    END IF;
END;
//
DELIMITER ;

-- 17. Total de consultas por veterinário
DELIMITER //
CREATE PROCEDURE totalConsultasPorVet (
    IN p_cod_vet INT
)
BEGIN
    SELECT COUNT(*) AS total_consultas FROM Consulta WHERE cod_vet = p_cod_vet;
END;
//
DELIMITER ;
