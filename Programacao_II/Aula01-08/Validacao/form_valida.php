<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style type="text/css">
        #form{
        margin: 0 auto;
        }
        table {
        margin: 0 auto;
        }
    </style>
    <title>Formulario a validar</title>
</head>
<body>
        <div id="form">
                <form action="valida.php" method="post">
                        <table>
                                <tr> <td>Nome: </td> <td><input type="text" size="50" name="nome"></td></tr>
                                <tr> <td>Email: </td> <td><input type="text" size="50" name="email"></td></tr>
                                <tr> <td>Sexo: </td> <td>
                                M<input type="radio" name="sexo" value="m">
                                F<input type="radio" name="sexo" value="f">
                                </td></tr>
                                <tr> <td>Estado: </td> <td>
                                <select name="estado">
                                        <option value="outro">Outro</option>
                                        <option value="pr">PR</option>
                                        <option value="sc">SC</option>
                                        <option value="rs">RS</option>
                                </select>
                                </td></tr>
                                <tr> <td>Interesses: </td> <td>
                                        Futebol <input type="checkbox" name="interesse" value="futebol">
                                        Tênis <input type="checkbox" name="interesse" value="tenis">
                                        Voleibol<input type="checkbox" name="interesse" value="voleibol">
                                </td></tr>
                                <tr> <td>Sugestão: </td> <td> <textarea name="sugestao" rows="3"
                                cols="36"></textarea></td></tr>
                                <tr><td colspan="2" align="center">
                                <input type="hidden" name="submetido" value="1">
                                <input type="submit" value="enviar">
                                </td></tr>
                                <tr><td colspan="2" align="center">
                                <?php
                                    require_once("valida.php");
                                ?>
                                </td></tr>
                        </table>
                </form>
        </div> 
</body>
</html>