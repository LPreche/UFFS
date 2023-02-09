#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>



int main(int argc, char *argv[])
{
    const char *conninfo;
    PGconn     *conn;
    PGresult   *res;
    int         nFields;
    int         i,
                j;

    /*
     * If the user supplies a parameter on the command line, use it as the
     * conninfo string; otherwise default to setting dbname=postgres and using
     * environment variables or defaults for all other connection parameters.
     */
    if (argc > 1)
        conninfo = argv[1];
    else
        conninfo = "host=localhost dbname=logwork user=postgres password=postgres";

    /* Make a connection to the database */
    conn = PQconnectdb(conninfo);

    /* Check to see that the backend connection was successfully made */
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        exit(1);
    }else
        printf("Conexao bem sucedida!");

    /*Teste de consulta
    res = PQexec(conn, "SELECT * FROM teste");
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        fprintf(stderr, "SELECT failed: %s", PQerrorMessage(conn));
        exit(1);
    }
    //Quantidade de atributos presentes
    nFields = PQnfields(res);

    //Percorrendo Tuplas
    for (i = 0; i < PQntuples(res); i++)
    {
        for (j = 0; j < nFields; j++)
            printf("%s ", PQgetvalue(res, i, j));
        printf("\n");
    }

    //Finalizando Conexão
    PQclear(res);
    PQfinish(conn);
    */
    return 0;
}
