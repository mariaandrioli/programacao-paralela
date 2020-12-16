# Trabalho Programação Paralela

> Dados: https://datasets.imdbws.com/ - titles.basics.tsv.gz


## Problema
O problema a ser tratado pelo grupo é a análise de grande quantidade de dados de forma paralela. Os dados que serão analisados são todos os filmes contidos no banco de dados da plataforma IMDB (Internet Movie Database). De acordo com a própria plataforma, a quantidade dados do tipo “Movie” em  Maio de 2019 era 516.726 e a quantidade total de títulos no banco era 5.980.614.  Como esses dados são atualizados diariamente e usaremos a versão mais recente possível, a quantidade de dados que analisaremos será um pouco maior.

## Proposta
Primeiramente faremos uma leitura e separação dos dados de modo a guardar apenas as informações que queremos (títulos com tipo “Movie”, o ano que este foi lançado e seus gêneros). Em seguida, faremos a contagem de cada gênero em cada ano, de forma a verificar se existe uma tendência em determinados períodos de tempo. Para paralelizar o código, usaremos OpenMP.

### Referências
- https://www.imdb.com/interfaces/
- https://en.wikipedia.org/wiki/IMDb
- https://www.imdb.com/pressroom/stats/
- https://pt.wikipedia.org/wiki/Gr%C3%A1fico_de_dispers%C3%A3o

### Autores

- Maria Teresa Andrioli 

[![Linkedin](https://i.stack.imgur.com/gVE0j.png) LinkedIn](https://www.linkedin.com/in/mariateresaandrioli/)
&nbsp;
[![GitHub](https://i.stack.imgur.com/tskMh.png) GitHub](https://github.com/mariaandrioli)

- Ana Carolina Magnoni
- Lucas Gabriel Lima
- Jean Guilherme Carraro