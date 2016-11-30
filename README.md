# LazyCanvas

## Objetivo

A criação de desenhos JavaScript no elemento canvas do HTML5 as vezes pode se tornar algo monótono, difícil e ser necessária enorme replicação de código para que o desenho fique do jeito desejado.

Tendo em vista esta dificuldade o _LazyCanvas_ vem para simplificar e facilitar a utilização deste enorme componente do HTML, e simplificando sua utilização para que leigos possam utilizá-lo sem muitos problemas.

## Utilização

Utilizando o JavaScript commum para desenhar no canvas, a criação de um circulo se daria pelo segundo código:

```JavaScript
var c=document.getElementById("myCanvas");
var ctx=c.getContext("2d");
ctx.beginPath();
ctx.arc(100,75,50,0,2*Math.PI);
ctx.stroke();
```

Enquanto em LazyCanvas apenas é necessário o seguinte:

```ruby
circle = Circle.new
draw(circle)
```

Outra grande vantagem, é a criação de objetos o que facilita a alteração de propriedades das figuras, reduzindo o código. Por exemplo, para criar um circulo em x = 100 y = 200 e depois criar outro igual porém no x = 200 y = 200, seria necessário o seguinte código:

```JavaScript
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
ctx.beginPath();
ctx.arc(100, 200, 50, 0, 2 * Math.PI);
ctx.stroke();
ctx.beginPath();
ctx.arc(200, 200, 50, 0, 2 * Math.PI);
ctx.stroke();
```

Enquanto em LazyCanvas:

```ruby
circle = Circle.new
circle.x = 100
circle.y = 200
draw(circle)

circle.x = 200
draw(circle)
```

## Documentação

A documentação pode ser encontrada em [aqui](https://github.com/LazyCanvas/LazyCanvas/wiki)

## TODO

Hoje a linguagem está incompleta, sendo necessárias várias correções e melhorias.

* Operações utilizando variáveis e números dentro de for's, por exemplo x = a + 1;
* Else;
* Estrutura de controle aninhadas;
