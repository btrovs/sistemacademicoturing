- Sistema Acadêmico - Faculdade Alan Turing:


- Descrição:
Este programa simula um sistema acadêmico simples de cadastro de informações pessoais. Ele permite ao usuário inserir ou editar dados como nome, data de nascimento, CPF, RG, e-mail, senha, estado, cidade e CEP, por meio de um menu interativo feito com switch case.


- Bibliotecas Utilizadas:
  - stdio.h: Entrada e saída padrão (ex: printf, scanf, fgets);

  - locale.h: Usada para configurar o idioma (ex: acentuação e a utilização de ç em português);

  - string.h: Funções de manipulação de strings (ex: strchr, strcspn);

  - stdbool.h: Permite o uso do tipo bool para variáveis booleanas;

  - ctype.h: Usada para verificar caracteres, como se são dígitos (isdigit).

- Funções de Validação:
  - bool validarEmail(const char *email):
  - Verifica se o e-mail contém um '@' e um '.' após o @;
  - Retorna true se o formato for considerado válido.

  - bool validarCPFFormatado(const char *cpf):
  - Verifica se o CPF segue o formato "000.000.000-00" (com pontos e traço);
  - Checa tamanho, posições dos separadores e se os demais caracteres são dígitos.
