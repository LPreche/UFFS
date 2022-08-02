<?php
        $fp = fopen("./dados.txt", "a"); // $fp conterá o retorno do 
        fwrite($fp,"\nhello World!");
        fclose($fp);
?>