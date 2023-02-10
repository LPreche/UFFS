#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include <libpq-fe.h>



int main(int argc, char *argv[])
{
    const char *conninfo;
    PGconn     *conn;
    PGresult   *res;
    int         nFields;
    int         i,j;

    if (argc > 1)
        conninfo = argv[1];
    else
        conninfo = "host=localhost dbname=postgres user=postgres password=postgres";

    conn = PQconnectdb(conninfo);


    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        exit(1);
    }

    res = PQexec(conn, "DROP DATABASE IF EXISTS logwork");
    res = PQexec(conn, "CREATE DATABASE logwork");
    
    PQclear(res);
    PQfinish(conn);
    //PGconn     *conn;   

    conninfo = "host=localhost dbname=logwork user=postgres password=postgres";
    conn = PQconnectdb(conninfo);

    if(PQstatus(conn) != CONNECTION_OK){
        fprintf(stderr, "Connection to database failed: %s",
        PQerrorMessage(conn));
        exit(1);
    }
    res = PQexec(conn, "CREATE TABLE Lredo (A int, B int)");

    // Read the JSON file
  json_error_t error;
  json_t *root = json_load_file("metadado.json", 0, &error);
  if (!root) {
    printf("Error loading JSON: on line %d: %s", error.line, error.text);
    PQfinish(conn);
    return 1;
  }

  // Iterate over the objects in the JSON array
  int i;
  for (i = 0; i < json_array_size(root); i++) {
    json_t *data = json_array_get(root, i);

    // Extract the values from the JSON object
    json_t *A = json_object_get(data, "A");
    json_t *B = json_object_get(data, "B");

    // Build and execute the SQL query
    char query[1024];
    sprintf(query, "INSERT INTO Lredo (A, B) VALUES ('%s', %d)",
            json_integer_value(A), json_integer_value(B));
    res = PQexec(conn, query);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
      printf("Insert failed: %s", PQerrorMessage(conn));
      json_decref(root);
      PQclear(res);
      PQfinish(conn);
      return 1;
    }
    PQclear(res);
  }

  // Clean up
  json_decref(root);
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
    */
    //Finalizando Conexão
    PQclear(res);
    PQfinish(conn);

    return 0;
}
