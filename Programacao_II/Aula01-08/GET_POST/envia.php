<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Enviar via Get</title>

    
</head>
<body>
    <?php
        if(isset($_GET['name'])){ // isset para saber se a variável foi definida
               echo ("<h3> parametro enviado por get: ". $_GET['name'] . "</h3>");
        }
        
        if(isset($_POST['name'])){
                echo ("<h3> parametro enviado por post: ". $_POST['name'] . "</h3>");
        }
        ?>
        <h1>Usando get</h1>
        <form method="get">
        <input type="text" name="name" placeholder="Digite algo">
        <input type="submit" value="Submeter">
        </form>
        <h1>Usando Post</h1>
        <form method="post">
        <input type="text" name="name" placeholder="Digite algo">
        <input type="submit" value="Submeter">
        </form>

</body>
</html>