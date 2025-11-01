# Sistema de Fila de Vacinação

Um programa em C que gerencia filas de espera e estoque de vacinas, organizando a vacinação de acordo com prioridades: idosos, pessoas com comorbidades e público geral.

## 📋 Descrição

Este projeto implementa um sistema de gerenciamento de vacinação utilizando estruturas de dados como **Filas** e **Pilhas**, tanto na versão estática quanto dinâmica. O sistema permite:

- Adicionar vacinas ao estoque (organizadas por grupo de prioridade)
- Registrar pessoas na fila de espera
- Processar vacinações respeitando prioridades
- Exibir relatório de sobras no final

## 🏗️ Estrutura do Projeto

```
├── FilaEstatica.h / FilaEstatica.c      # Implementação estática da fila
├── FilaDinamica.h / FilaDinamica.c      # Implementação dinâmica da fila
├── PilhaEstatica.h / PilhaEstatica.c    # Implementação estática da pilha
├── PilhaDinamica.h / PilhaDinamica.c    # Implementação dinâmica da pilha
└── main.c                                # Programa principal
```

## 👥 Prioridades de Vacinação

1. **Idosos** (idade ≥ 60 anos) - Fila `idoso`
2. **Pessoas com Comorbidades** - Fila `comorbidade`
3. **Público Geral** - Fila `geral`

## 📝 Formato de Entrada

O programa lê comandos do usuário:

### Adicionar Vacinas
```
i <marca> <lote> <quantidade>    # Para idosos
c <marca> <lote> <quantidade>    # Para comorbidades
g <marca> <lote> <quantidade>    # Para público geral
```

### Gerenciar Pessoas
```
+ <nome> <idade> <comorbidade>   # Adicionar pessoa na fila
- <fila>                          # Vacinar primeira pessoa da fila
F                                 # Finalizar programa
```

**Exemplo de comorbidade:** `S` (sim) ou `N` (não)

## 💉 Exemplo de Uso

```
i Pfizer 001 10
c AstraZeneca 002 5
g Janssen 003 8
+ Maria 65 N
+ João 45 S
+ Pedro 30 N
- idoso
- comorbidade
- geral
F
```

## 🎯 Saída Esperada

```
Maria (65 anos, sem comorbidades), vacinado(a) com Pfizer, lote n. 1
João (45 anos, com comorbidades), vacinado(a) com AstraZeneca, lote n. 2
Pedro (30 anos, sem comorbidades), vacinado(a) com Janssen, lote n. 3
--
Restaram 0 idoso(s).
Restaram 0 pessoa(s) com comorbidades.
Restaram 0 pessoa(s) no geral.
--
Sobraram 9 dose(s) para idosos.
Sobraram 4 dose(s) para pessoas com comorbidades.
Sobraram 7 dose(s) para pessoas no geral.
```

## 🛠️ Compilação

```bash
gcc main.c FilaEstatica.c PilhaEstatica.c -o vacinacao
```

Ou com a versão dinâmica:

```bash
gcc main.c FilaDinamica.c PilhaDinamica.c -o vacinacao
```

## ▶️ Execução

```bash
./vacinacao
```

## 📚 Estruturas de Dados

### Pessoa
```c
typedef struct {
    char nome[100];
    int idade;
    char comorbidade[2];
} Pessoa;
```

### Vacina
```c
typedef struct {
    char marca[20];
    int lote;
} Vacina;
```

## 🔑 Funções Principais

### Fila
- `Fila *cria_fila()` - Criar nova fila
- `void push_fila()` - Adicionar pessoa na fila
- `Pessoa pop_fila()` - Remover pessoa da fila
- `int Vazia()` - Verificar se fila está vazia
- `int tamanho_fila()` - Obter tamanho da fila

### Pilha
- `Pilha *cria_pilha()` - Criar nova pilha
- `void push_pilha()` - Adicionar vacina na pilha
- `Vacina pop_pilha()` - Remover vacina da pilha
- `int vazia()` - Verificar se pilha está vazia
- `int tamanho_pilha()` - Obter tamanho da pilha

## 💻 Características

- ✅ Gerenciamento de 3 grupos de prioridade
- ✅ Implementações estática e dinâmica
- ✅ Validação de filas e estoques vazios
- ✅ Relatório final detalhado
- ✅ Desalocação automática de memória

## 📌 Notas

- O programa utiliza a versão **estática** por padrão (main.c importa FilaEstatica.h)
- Para usar a versão **dinâmica**, altere os includes em main.c
- Lembre-se de finalizar com `F` para gerar o relatório e liberar memória

## 👨‍💻 Autor

Desenvolvido como trabalho acadêmico de Estruturas de Dados.

## 📄 Licença

Livre para uso educacional.
