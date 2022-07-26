function    init[]{
    var btn=document.getElementById('btn');
    btn.addEventListener('click',function(event){
        var p1 = document.getElementById('p1');
        p1.classList("vermelho");
    })
    console.log("tudo certo");
}
document.addEventListener('DOMContentLoaded',init);