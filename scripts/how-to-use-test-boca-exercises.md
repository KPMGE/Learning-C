### Teste automático de questões para o Boca
No primeiro periodo de programação, estudei os conceitos básicos de programação usando a linguagem C,
no entanto, me dei conta que poderia automatizar um pouco o sistema por onde treinávamos a construção de programas simples,
o Boca. Você pode encontrar um script na pasta scripts desse repositório que pode lhe ajudar. 

Basicamente, este programa testará as entradas e saídas do programa boca, e caso haja algum problema, por menor que seja, o mesmo será
exibindo, permitindo-o sanálo.

#### Como usar o script?
Você pode simplesmente baixá-lo da pasta __scripts__, o nome do programa é **test-boca-exercises.sh**, depois de baixar o programa,
mova-o para o seu diretório Home. Certifique-se de que está usando um sistema linux, quer seja ele uma distro linux em si, ou mesmo 
um subsistema. Nesse caso, dê permissão de execução para o script, usando o comando:

`chmod +x test-boca-exercises.sh`

Tudo Pronto! Agora você pode simplesmente executar o programa sempre que quiser testar algum exercício, usando:

`./test-boca-exercises`

No primeiro uso, o script perguntará se você deseja instalar alguns pacotes que serão usados para renderizar alguns componentes visuais 
bonitinhos rs. Caso não os queira, você pode editar o script.

Depois que tudo estiver instalado, você precisará se organizar um pouco


crie uma pasta para conter os arquivos __.zip__ do Boca, e outra pasta contendo seus arquivos fonte __.c__ com suas resoluções
propriamente ditas


Com tudo pronto, o programa lhe perguntará qual o nome do arquivo que você deseja testar, sem a sua extensão __.c__,
logo após isso, será pedido o endereço da pasta na qual você criou suas resoluções do Boca, forneça-a. Por fim, 
será pedido o endereço da pasta contendo seus arquivos __.zip__ com as questões do Boca, forneça-o também. Pronto! caso algum erro ocorra,
uma mensagem com suspeitas do que ocorreu aparecerá, caso contrário, todos os testes constarão como vazios.



Ufa! Tudo bem até agora? 
Então vamos lá! Falta pouco ... rs


###  Automatizando passagem de caminhos para arquivos
Vamos lá, este é o ultimo passo para deixar seu script mais conveniente, pois pode ser inconveniente passar
os caminhos para as pastas onde constam seus arquivos sempre, para resolver isso, você pode remover as linhas __39 a 44__ do seu
script, onde a leitura é feita. Após isso, você deve definir os caminhos para suas pastas de forma perene. Para isso, no lugar das linhas
que lá constavam, acidione duas variáveis:

`wayFile = <caminho para o arquivo .c>`  
`wayZip = <caminho para o arquivo .zip>`  
