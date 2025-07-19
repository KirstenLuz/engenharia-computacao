CREATE SCHEMA hospital;
USE hospital;
-- Questão 1 --
CREATE TABLE paciente (
	id INTEGER PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL,
    celular VARCHAR(15) NOT NULL
    );

CREATE TABLE especialidade (
	id INTEGER PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(100) NOT NULL
    );
    
CREATE TABLE medico (
	id INTEGER PRIMARY KEY AUTO_INCREMENT,
    id_especialidade INTEGER NOT NULL,
    nome VARCHAR(100) NOT NULL,
    celular VARCHAR(15) NOT NULL,
    FOREIGN KEY (id_especialidade) REFERENCES especialidade(id)
    );

DROP TABLE consulta;

CREATE TABLE consulta (
	id INTEGER PRIMARY KEY AUTO_INCREMENT,
    id_medico INTEGER NOT NULL,
    id_paciente INTEGER NOT NULL,
    data_hora_inicio DATETIME NOT NULL,
    data_hora_fim DATETIME NOT NULL,
    FOREIGN KEY (id_medico) REFERENCES medico(id),
    FOREIGN KEY (id_paciente) REFERENCES paciente(id)
    );


-- Questão 2 --
INSERT INTO especialidade (nome) VALUES
('Cardiologia'),
('Oftalmologia'),
('Pediatria');

select * from especialidade;

INSERT INTO medico (nome, id_especialidade, celular) VALUES
('Beatriz',1,'(47) 98877-9182'),
('José',3,'(47) 97788-8291'),
('Ana',1,'(47) 92939-4599'),
('Gustavo',2,'(47) 98859-4539'),
('Paulo',1,'(47) 94782-9762'),
('Carlos',3,'(47) 91772-4321');

select * from medico;

INSERT INTO paciente (nome, celular) VALUES
('Marina','(55) 92134-4221'),
('Marcos','(47) 91223-7966'),
('Maicon','(55) 90932-7822'),
('Roberta','(55) 92318-7238'),
('Joaquim','(49) 98424-9237'),
('Bianca','(47) 90000-3424'),
('Pedro','(49) 91462-0192');

select * from paciente;

INSERT INTO consulta (id_medico, id_paciente, data_hora_inicio, data_hora_fim) VALUES
-- Dia 08 --
-- Beatriz --
(1,4,'2025-12-08 10:00:00', '2025-12-08 11:30:00'), -- Roberta
(1,5,'2025-12-08 11:30:00', '2025-12-08 12:00:00'), -- Joaquim
(1,6,'2025-12-08 13:30:00', '2025-12-08 14:30:00'), -- Bianca
-- José --
(2,2,'2025-12-08 08:00:00', '2025-12-08 10:00:00'), -- Marcos
(2,3,'2025-12-08 10:00:00', '2025-12-08 11:00:00'), -- Maicon
(2,1,'2025-12-08 11:00:00', '2025-12-08 12:00:00'), -- Mariana

-- Dia 09 --
-- Paulo --
(5,7,'2025-12-09 08:30:00', '2025-12-09 09:30:00'), -- Pedro
-- Gustavo --
(4,7,'2025-12-09 09:00:00', '2025-12-09 10:00:00'), -- Pedro
(4,5,'2025-12-09 11:00:00', '2025-12-09 12:00:00'), -- Joaquim
(4,6,'2025-12-09 13:30:00', '2025-12-09 14:30:00'), -- Bianca
(4,2,'2025-12-09 14:30:00', '2025-12-09 15:30:00'); -- Marcos

select * from consulta;

-- Questão 3 --
UPDATE paciente SET celular = '(47) 97766-9843' WHERE id = 6;
UPDATE paciente SET celular = '(47) 97465-9543' WHERE id = 2;
select * from paciente;

-- Questão 4 --
DELETE FROM consulta WHERE id = 3;
select * from consulta;

-- Questão 6 --
-- 1)
SELECT m.nome, COUNT(c.id) AS total_consultas
	FROM medico m
	LEFT JOIN consulta c ON c.id_medico = m.id
	GROUP BY m.nome
	ORDER BY m.nome;

-- 2)
SELECT e.nome AS especialidade, COUNT(c.id) AS total_consultas
	FROM especialidade e
	JOIN medico m ON m.id_especialidade = e.id
	LEFT JOIN consulta c ON c.id_medico = m.id
	GROUP BY e.nome
	ORDER BY e.nome;

-- 3)
SELECT 
    DATE_FORMAT(data_hora_inicio, '%d/%m') AS dia_mes,
    MAX(TIMESTAMPDIFF(MINUTE, data_hora_inicio, data_hora_fim)) AS maior_duracao_minutos
	FROM consulta
	GROUP BY DATE(data_hora_inicio)
	ORDER BY DATE(data_hora_inicio);
    
-- 4)
SELECT 
    COUNT(c.id) AS total_consultas,
    e.nome AS especialidade,
    m.nome AS mais_atendimentos
    
	FROM consulta c
	JOIN medico m ON c.id_medico = m.id
	JOIN especialidade e ON m.id_especialidade = e.id
	GROUP BY m.id
	ORDER BY especialidade DESC
    LIMIT 3;

-- 5)
SELECT
	m.nome, p.nome, c.data_hora_inicio
    
    FROM consulta c 
    JOIN medico m ON c.id_medico = m.id 
    JOIN paciente p ON c.id_paciente = p.id
    WHERE DATE(c.data_hora_inicio) = '2025-12-08'
    group by p.id 
    ORDER BY c.data_hora_inicio;
    
-- 6)
SELECT
	TIMESTAMPDIFF(MINUTE, data_hora_inicio, data_hora_fim) AS Diferenca_tempo,
    id AS id_consulta
    From consulta c
    WHERE DATE(c.data_hora_inicio) = '2025-12-09';
    
-- 7)
SELECT c.*, p.nome AS Nome_Paciente
    FROM consulta c 
    JOIN paciente p ON c.id_paciente = p.id
    WHERE c.id_medico = 4;

-- 8)
SELECT 
    m.nome AS nome_medico,
    DATE(c.data_hora_inicio) AS data_consulta,
    COUNT(c.id) AS total_consultas
    
	FROM consulta c
	JOIN medico m ON c.id_medico = m.id
	GROUP BY m.nome, DATE(c.data_hora_inicio)
	ORDER BY data_consulta, m.nome;
    
-- 9)
SELECT *
	FROM consulta
    WHERE TIME(data_hora_inicio) > '13:00:00';

-- 10)
SELECT 
	c1.id AS consulta_1,
	c2.id AS consulta_2,
	c1.data_hora_inicio AS inicio_1,
	c1.data_hora_fim AS fim_1,
	c2.data_hora_inicio AS inicio_2,
	c2.data_hora_fim AS fim_2,
	DATE(c1.data_hora_inicio) AS data_consulta
    
	FROM consulta c1
	JOIN consulta c2 
	ON c1.id < c2.id
	AND c1.id_paciente = c2.id_paciente
	AND DATE(c1.data_hora_inicio) = DATE(c2.data_hora_inicio)
	AND c1.id_paciente = 7
	AND (
		c1.data_hora_inicio BETWEEN c2.data_hora_inicio AND c2.data_hora_fim
		OR
		c2.data_hora_inicio BETWEEN c1.data_hora_inicio AND c1.data_hora_fim
	)
	ORDER BY data_consulta;
	
-- 11)
SELECT nome, CHAR_LENGTH(nome) AS quantidade_caracteres
	FROM paciente;
    
-- 12)
SELECT * FROM medico WHERE nome LIKE 'P%';

-- 13)
SELECT
	CONCAT(m.nome,' (',e.nome,')') AS nome_especialidade
    FROM medico m
    JOIN especialidade e WHERE m.id_especialidade = e.id;
    
-- 14)
SELECT
	REPLACE(nome, 'sta', 'ia')
	FROM especialidade;
    