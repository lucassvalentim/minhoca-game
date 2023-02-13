# MINHOCA

## Sobre 

![image](https://user-images.githubusercontent.com/72881147/218588563-c4e46fd5-6722-458d-bab9-679408c2e206.png)

![image](https://user-images.githubusercontent.com/72881147/218588612-a7aa460f-d55f-407f-8fa4-d38583773399.png)

![image](https://user-images.githubusercontent.com/72881147/218588749-db9966d0-6458-409d-930d-f2ab176d8c97.png)

![image](https://user-images.githubusercontent.com/72881147/218588776-1db77c59-b5ae-45e9-814b-b92341361a03.png)


O jogo consiste em uma cobra que será movimentada pelo jogador em uma tela
limitada (600x350) 2d. O seu objetivo é coletar quantas maçãs conseguir sem esbarrar
nos limites da tela ou em si mesma. A cada coleta, a cobra cresce um segmento e,
também, é contado um ponto para o jogador ( esse ponto é mostrado na tela e
atualizado a cada recolhimento da maçã ) que, caso seu ponto ultrapassar algum dos 5
primeiros lugares do ranking, o seu nome entra na lista. É possível ver o ranking ao
escolher essa opção na tela de menu iniciar, onde também é possível começar o jogo.
Logo após, será então pedido a escolha da dificuldade na qual o jogador jogará, em
que cada nível de dificuldade a velocidade será maior ou menor, dependendo da
escolha. Por fim, será pedido seu apelido para o registro da informação de seus
pontos.
Bom jogo

## Comandos Importantes:
<p><h3>Para rodar o jogo no Windows, coloque os seguintes comandos no terminal</h3></p>
<p> -> git clone --recursive https://github.com/syndelis/jogo-aeds-1 tp-aeds1<br>
-> cd tp-aeds1</p>

<p> -> git submodule update --init --recursive # Só precisa rodar uma vez<br>
-> .\utils\windows-build.ps1 # Rode sempre que quiser compilar</p>

<p>-> .\compilar.ps1<br>
-> ./jogo </p>

<p><h3>Para rodar o jogo no Linux, coloque os seguintes comandos no terminal</h3></p>
<p> -> git clone --recursive https://github.com/syndelis/jogo-aeds-1 tp-aeds1<br>
-> cd tp-aeds1</p>

<p> -> git submodule update --init --recursive<br>
-> sudo apt install build-essential cmake<br>
-> case $XDG_SESSION_TYPE in<br>
    x11) sudo apt install xorg-dev ;;<br>
    wayland) sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules;;<br>
    *) echo "Não foi possível determinar o tipo de sessão que está sendo usada" ;;<br>
esac </p>

<p>-> make<br>
-> ./jogo </p>


## Teclas importantes.
  
<br> Para sair do jogo: aperte ESC.<br>
Para começar o jogo ou entrar no rank: aperte ENTER.<br>
Para escolher a dificuldade: aperte ESPAÇO.<br>
Para voltar a uma decisão: aperte S.<br>
Para mover a cobra: utilize as setas CIMA, ESQUERDA, BAIXO, DIREITA.<br><br>
