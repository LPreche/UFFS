DROP FUNCTION IF EXISTS exclui_produto CASCADE;

CREATE OR REPLACE FUNCTION exclui_produto()
RETURNS trigger AS 
$$
BEGIN
	
	IF NEW.quantity <= 0 THEN
		DELETE FROM stock WHERE NEW.eid = eid;
		DELETE FROM product WHERE NEW.eid = eid;
	END IF;

	RETURN NEW;

END
$$
LANGUAGE plpgsql;

CREATE TRIGGER verifica_estoque AFTER UPDATE ON stock
FOR EACH ROW EXECUTE PROCEDURE exclui_produto();

--UPDATE stock set quantity = quantity - quantity where eid = 1;
