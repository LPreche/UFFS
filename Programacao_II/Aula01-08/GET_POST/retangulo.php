<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
            function ret($x, $y){
                return $x * $y;
            }
            $a = ret($_POST["x"], $_POST["y"]);
            echo "Um retangulo com lados " . $_POST["x"] . " e " . $_POST["y"] . " tem área de " . $a;
    ?>
</body>
</html>