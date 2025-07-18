-- Consultas SQL
use clinica_vet;
SET SQL_SAFE_UPDATES = 0;

SELECT * FROM Animal;
SELECT * FROM Tutor;
SELECT * FROM Tutor_endereco;
SELECT * FROM Veterinario;
SELECT * FROM Veterinario_endereco;
SELECT * FROM consulta;

-- 1 --
SELECT nome, raca, data_nasc FROM Animal;
-- 2 --
UPDATE Animal SET especie = "Canino" WHERE especie = "Cachorro";
UPDATE Animal SET especie = "Felino" WHERE especie = "Gato";
SELECT * FROM Animal;
-- 3 --
SELECT nome, peso, raca FROM Animal WHERE peso >= 5 and peso < 10;
-- 4 --
SELECT cep, rua, cidade FROM Veterinario_endereco WHERE complemento IS NULL;
-- 5 --
SELECT v.nome, v.fone, e.cep, e.cidade 	
	FROM Veterinario v, Veterinario_endereco e	
	WHERE v.id = e.id_vet;
-- 6 --
SELECT t.nome, te.cidade, te.cep, a.nome
	FROM Tutor t
    JOIN Tutor_endereco te ON (t.id = te.id_tutor)
    JOIN Animal a ON (a.id_tutor = t.id);
-- 7 --
SELECT v.nome, a.nome, c.dt
	FROM Consulta c
	JOIN Animal a ON (a.id = c.id_animal)
    JOIN Veterinario v ON (v.id = c.id_vet)
    WHERE dt LIKE '2024-09-__'
    ORDER BY c.dt DESC;
-- 8 --
SELECT t.id, t.nome AS nome_tutor, a.nome AS nome_animal
FROM Tutor t
LEFT JOIN Animal a ON t.id = a.id_tutor;
-- relacionei para ver os tutores que não possuiam animal --

SELECT DISTINCT t.id, t.nome, t.cpf 
    FROM Tutor t 
    LEFT JOIN Animal a ON (t.id = a.id_tutor) 
    WHERE a.nome IS NULL;

-- 9 --
SELECT * FROM Animal WHERE id_tutor IS NULL;

-- 10 -- 
SELECT sexo, COUNT(*) FROM Animal GROUP BY sexo;

-- 11 -- 
SELECT a.nome, c.dt, c.horario 
    FROM Consulta c
    JOIN Animal a ON (a.id = c.id_animal)
    WHERE c.id_vet = 2;

-- 12 -- 
SELECT v.nome, COUNT(*) AS total_consultas
    FROM Consulta c
    JOIN Veterinario v ON (v.id = c.id_vet)
    GROUP BY v.nome
    ORDER BY total_consultas DESC;

-- 13 -- 
SELECT v.especialidade, COUNT(*) AS total_consultas
    FROM Consulta c
    JOIN Veterinario v ON v.id = c.id_vet
    GROUP BY v.especialidade;
-- todos possuem mesma quantidade de consultas --

-- 14 --
SELECT a.nome, COUNT(*) AS total_consultas
FROM Consulta c
JOIN Animal a ON c.id_animal = a.id
GROUP BY a.nome
ORDER BY total_consultas DESC, a.nome ASC
LIMIT 1;
-- todos os animais possuem a mesma quantidade de consultas, coloquei o resultado por ordem alfabetica -- 
