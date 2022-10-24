DROP FUNCTION IF EXISTS registra_log CASCADE;
DROP TABLE IF EXISTS logs;

CREATE TABLE logs(eid varchar(20), data timestamp , usuario text);

CREATE OR REPLACE FUNCTION registra_log()
RETURNS trigger AS 
$$
BEGIN
	
	INSERT INTO logs(eid,data,usuario) VALUES(OLD.eid,current_timestamp,current_user);
	RETURN NEW;

END
$$
LANGUAGE plpgsql;

CREATE TRIGGER verifica_ AFTER UPDATE ON stock
FOR EACH ROW EXECUTE PROCEDURE registra_log();

--UPDATE stock set quantity = quantity - 2 where eid = 1;
