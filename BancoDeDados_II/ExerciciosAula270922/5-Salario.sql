create table users (id int, nome varchar(50), salario real);

insert into users (id,'nome',salario) values (1,'Joao',5980),
                                       (2,'Maria',19000),
                                       (3,'Pedro',10500),
                                       (4,'Davi',8000),
                                       (5,'Edgar',1000);

CREATE OR REPLACE FUNCTION calcula_salario(int)
RETURNS setof users
AS
$$
DECLARE
    sal real := (select salario from users u where u.id=$1);
BEGIN
    IF(sal >= 10000) THEN
        sal = sal + (sal * 0.01);
        UPDATE users u set salario = sal where u.id=$1;
        RETURN QUERY SELECT * FROM users u where u.id=$1;
    ELSIF(sal < 10000) THEN
        sal = sal = (sal * 0,05);
        UPDATE users u set salario = sal where u.id=$1;
        RETURN QUERY SELECT * FROM users u where u.id=$1;
    END IF;
    RETURN;
END;
$$
LANGUAGE plpgsql;


SELECT * FROM calcula_salario(1);