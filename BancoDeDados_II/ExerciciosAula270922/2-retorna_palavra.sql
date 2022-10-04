CREATE OR REPLACE FUNCTION retorna_palavra(palavra varchar)

RETURNS VOID
AS
$$
BEGIN
	RAISE NOTICE '%',palavra;

END;
$$
LANGUAGE plpgsql;

select * from retorna_palavra('teste');
