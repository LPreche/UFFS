<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulario</title>
</head>
<body>
    <form action="cadastro.php" method="POST">
        <fieldset>
            <legend>Formulário de contato</legend>
            <label for="nome">Nome:</label>
            <input type="text" name="nome"> 
            <br>
            <label for="email">Email:</label>
            <input type="email" name="email" id="email">
            <br>
            <label for="telefone">Telefone:</label>
            <input type="number" name="telefone" id="telefone">
            <br>
            <label for="pass">Password:</label>
            <input type="password" name="pass" id="pass">
            </fildset>
    </form>
    <br><label for="dn">Data de nascimento:</label>
    <input type="date" name="dn" id="dn">
    <br>
    <label for="genero">Genero:</label>
    <input type="radio" name="genero" id="generoM" id="M">Masculino
    <input type="radio" name="genero" id="generoF" id="F">Feminino
    <br>
    
    <select name="curso" id="curso">
        <option value="Programação">Programação</option>
        <option value="Redes" selected>Redes</option>
        <option value="Circuitos">Circuitos</option>
    </select><br>
    <button input type=“submit”>Enviar</button>   
</body>
</html>