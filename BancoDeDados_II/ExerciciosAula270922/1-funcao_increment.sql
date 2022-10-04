CREATE OR REPLACE FUNCTION funcao_increment(n int)

RETURNS int
AS $$
BEGIN
	RETURN $1 + 1;
END;
$$

LANGUAGE plpgsql;


select * from funcao_increment(1);
