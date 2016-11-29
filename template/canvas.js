var myCanvas = document.getElementById("lazy_canvas");
var ctx = myCanvas.getContext("2d");
ctx.beginPath();
ctx.arc(100.000000, 100.000000, 50.000000, 0, 2 * Math.PI);
ctx.stroke();
ctx.fill();
ctx.beginPath();
ctx.arc(250.000000, 100.000000, 50.000000, 0, 2 * Math.PI);
ctx.fillStyle = "#DCDCDC";
ctx.lineWidth = 2.000000;
ctx.stroke();
ctx.fill();
ctx.beginPath();
ctx.moveTo(500.000000,500.000000);
ctx.lineTo(550.000000,400.000000);
ctx.stroke();
ctx.fill();
ctx.beginPath();
ctx.rect(400.000000,400.000000,200.000000,300.000000);
ctx.fillStyle = "black";
ctx.lineWidth = 5.000000;
ctx.stroke();
ctx.fill();
ctx.beginPath();
ctx.arc(200.000000,200.000000,50.000000,(0.000000 / 180) * Math.PI , (180.000000 / 180) * Math.PI);
ctx.fillStyle = "red";
ctx.lineWidth = 3.000000;
ctx.stroke();
ctx.fill();
ctx.beginPath();
ctx.moveTo(350.000000, 350.000000 - 50.000000/2);
ctx.bezierCurveTo(350.000000 + 100.000000/2, 350.000000 - 50.000000/2, 350.000000 + 100.000000/2, 350.000000 + 50.000000/2, 350.000000, 350.000000 + 50.000000/2);
ctx.bezierCurveTo(350.000000 - 100.000000/2, 350.000000 + 50.000000/2, 350.000000 - 100.000000/2, 350.000000 - 50.000000/2, 350.000000, 350.000000 - 50.000000/2);
ctx.stroke();
ctx.fill();
