#### Ferramentas nescessarias para compilar os projetos para Windows XP
- Mingw (Minimalist GNU for Windows)
    - i686-w64-mingw32-c++ (Testado para Windows XP)
- Visual Studio 2017
    - VC++ 2017 15.9
    - Suporde do Windows XP para C++



---
### Atenção
__Sempre fazer uma cópia do arquivo Gcode antes de modifica-lo__

---

###### g1z20.cpp
Busca por linhas que começam com **_G1Z_**, alterando o valor do eixo de 0.000 para 20.000 e adicionando a instrução M3 ao final da linha.
###### x2a.cpp
Substitui todas as referencias ao eixo **X** para o eixo **A**

