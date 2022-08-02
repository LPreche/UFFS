<?php
        if(isset($_POST["submetido"]) && $_POST["submetido"]==1){//validar form
            $erros = "";
            if(empty($_POST["nome"])){
                $erros = "Ajuste o nome.";
            }
            if(empty($_POST["email"])){
                if($erros){
                    $erros .= ", email.";
                }else{
                    $erros="Ajuste o email.";
                }
            }
            if(!empty($erros)){
                echo $erros;
            }else{
                echo"<br>Formulario enviado!";
            }
        }
?>
