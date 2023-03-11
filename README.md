# MINHOCA

## Sobre 

<p align = "center">
    <img width = 450 src = "https://user-images.githubusercontent.com/72881147/218588563-c4e46fd5-6722-458d-bab9-679408c2e206.png">
    <img width = 450 src = "https://user-images.githubusercontent.com/72881147/218588612-a7aa460f-d55f-407f-8fa4-d38583773399.png">
</p>  

<p align = "center">
    <img width = 450 src = "https://user-images.githubusercontent.com/72881147/218588749-db9966d0-6458-409d-930d-f2ab176d8c97.png">
    <img width = 450 src = "https://user-images.githubusercontent.com/72881147/218588776-1db77c59-b5ae-45e9-814b-b92341361a03.png">
</p>

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

<strong>Obs: Ler "Teclas importantes" para maiores dificuldades!</strong>

# Comandos Importantes:
### Como rodar o jogo no Windows:
<p> 1º) Clone o repositório em seu computador</p>
<p> 2º) Abra o terminal e certifica-se de que está do diretório tp-aeds1, com o seguinte comando:</p>

```
PS > cd tp-aeds1
```
<p>
    3º) Para compilar nativamente no Windows, você vai precisar instalar o MinGW64, que traz as ferramentas GNU de compilação para o Windows.
</p>
<p>
    4º) Você também precisará do comando CMake que pode ser instalado da seguinte forma:
</p>

```
PS > winget install Kitware.CMake
```

<p>
    5º) Após isso, rode este comando no seu PowerShell
</p>

```
PS > git submodule update --init --recursive # Só precisa rodar uma vez
PS > .\utils\windows-build.ps1 # Rode sempre que quiser compilar
```

<p>
    5º) A biblioteca estará compilada. Para apagar os arquivos compilados, rode:
</p>

```
PS > .\utils\windows-clean.ps1
```
<p> 6º) Para compilar e inicializar o jogo, rode:

```
PS > .\compilar.ps1
PS > ./jogo 
```

### Para rodar o jogo no Linux, coloque os seguintes comandos no terminal:

<h4> Distribuições baseadas em Debian (Ubuntu/Pop_OS!/ElementaryOS):</h4>

```
$ git submodule update --init --recursive
$ sudo apt install build-essential cmake
$ case $XDG_SESSION_TYPE in
    x11) sudo apt install xorg-dev ;;
    wayland) sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules;;
    *) echo "Não foi possível determinar o tipo de sessão que está sendo usada" ;;
esac
```

<h4> Distribuições baseadas em ArchLinux: </h4>

```
$ git submodule update --init --recursive
$ case $XDG_SESSION_TYPE in
    x11) sudo pacman -S libx11 ;;
    wayland) sudo pacman -S wayland ;;
    *) echo "Não foi possível determinar o tipo de sessão que está sendo usada";
esac
```

<h4> Compição e inicialização: (certifica-se de estar no diretório tp-aeds1)</h4>

```
$ cd tp-aeds1
$ make
$ ./jogo 
```


## Teclas importantes.
  
<br> Para sair do jogo: aperte ESC.<br>
Para começar o jogo ou entrar no rank: aperte ENTER.<br>
Para escolher a dificuldade: aperte ESPAÇO.<br>
Para voltar a uma decisão: aperte S.<br>
Para mover a cobra: utilize as setas CIMA, ESQUERDA, BAIXO, DIREITA.<br><br>

### Para maiores informações e dúvidas, acesse o repositório original: [clique aqui](https://github.com/Syndelis/jogo-aeds-1)
