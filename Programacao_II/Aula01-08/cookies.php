<?php
    /* Dura ate o fechamento do browser*/
    setcookie('meucookie1','PHP');
    /* Dura 1 hora*/
    setcookie('meucookie2','WEB',time()+3600);
    
    echo $_COOKIE['meucookie1'].'<br>';
    echo $_COOKIE['meucookie2'].'<br>';
    print_r($_COOKIE);
?>