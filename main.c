#include <stdio.h>
#include <stdlib.h>

var klikken = Math.ceil(9*Math.random());
var totaal = klikken*Math.random()*5;
var aantalhtml = document.getElementById('clicks')
var rank = document.getElementById('ranking');
var sterren = document.querySelectorAll('.leeg');

function setsterkleur(ster, percentage){
    var selectster = 's' + ster;
    percentage =  Math.min(percentage, 100);
    document.getElementById(selectster).style.width = percentage+'%';
}
setsterkleur(4, 100);

function kleursterren(waard)
{
    for(var i=1; i<6; i++){
        setsterkleur(i, waard*100);
        waard --;
    }
}

function uit(){
    aantalhtml.innerHTML = klikken;
    rank.innerHTML = Math.ceil(10*totaal/klikken)/10;
    kleursterren(Math.ceil(10*totaal/klikken)/10);
}
uit();

function verwerk() {
    klikken ++;
    var num = this.getAttribute("data-role");
    totaal += parseInt(num);
    uit();
}

for(var i=0; i<sterren.length; i++){

    sterren[i].addEventListener('click', verwerk);
}
