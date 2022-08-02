<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mostra cadastro</title>
</head>
<body>
    <h3>Bem-vindo </h3>


    <?php
        echo $_POST["nome"]." - ".$_POST["email"]."-".$_POST["telefone"];
    ?>

</body>
</html>