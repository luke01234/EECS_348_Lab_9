let boR = document.getElementById("borderR");

let boG = document.getElementById("borderG");

let boB = document.getElementById("borderB");

let bgR = document.getElementById("bgR");

let bgG = document.getElementById("bgG");

let bgB = document.getElementById("bgB");

let bw = document.getElementById("borderWidth");

let para = document.getElementById("para1");


function NormalizeInput(input)

{

    if (input.value>255)

    {

        input.value=255

        return 255;

    }

    else if (input.value<0)

    {  

        input.value=0;

        return 0;

    }

    else if (isNaN(input.value) || input.value=="")

    {

        input.value=0;

        return 0;

    }

    else

    {

        return input.value;

    }

}


function NormalizeWidth(input)

{

    if (input.value<0)

    {  

        input.value=0;

        return 0;

    }

    else if (isNaN(input.value) || input.value=="")

    {

        input.value=0;

        return 0;

    }

    else

    {

        return input.value;

    }

}


function Set_Para_Color()

{

    boRValue=NormalizeInput(boR);

    boGValue=NormalizeInput(boG);

    boBValue=NormalizeInput(boB);

    bgRValue=NormalizeInput(bgR);

    bgGValue=NormalizeInput(bgG);

    bgBValue=NormalizeInput(bgB);

    bwValue=NormalizeWidth(bw);

    console.log(bwValue);


    para.style.borderColor = `rgb(${boRValue},${boGValue},${boBValue})`;

    para.style.borderWidth = `${bwValue}px`;

    para.style.backgroundColor = `rgb(${bgRValue},${bgGValue},${bgBValue})`;

}