DROP FUNCTION if exists maior_media();
DROP TABLE if exists usuario;
CREATE TABLE usuario (id int, nome varchar(50));


INSERT INTO usuario (id,nome) values (1,'jose'),
				     (2,'maria'),
				     (3,'edgar'),
				     (4,'cold'),
				     (5,'boyce');



CREATE FUNCTION maior_media()
RETURNS setof usuario
AS
$$
BEGIN
	RETURN QUERY SELECT * from usuario as u where u.id > (select avg(id) from usuario) ;
END;
$$
LANGUAGE plpgsql;

select * from maior_media();
