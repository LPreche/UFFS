
CREATE OR REPLACE FUNCTION calcula_valor(int,real)
RETURNS real
AS
$$
DECLARE 
op INT:= $1;
valor REAL := $2;

BEGIN
	IF OP = 1 THEN
		return valor + (valor * 0.10);
    end if;
	if OP = 2 THEN
		return valor - ( valor * 0.10);
    END IF;
END;
$$
LANGUAGE plpgsql;

select * from calcula_valor(1,1000.00);
