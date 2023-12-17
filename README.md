# Tabela Hash

Implementação de uma tabela hash, arquivo principal utiliza a tabela para remover duplicatas do arquivo csv.

Uso:
```
removeDuplicates <arquivo .csv>
```

# Classe hashTable
A implementação da tabela hash foi feita no arquivo "hashTable.h". A classe utiliza argumentos templates para chave e tipo.

A tabela utiliza da classe std::vector para a criação de buckets dinâmicos. O número de buckets criados está definido na macro "NUMBER_OF_BUCKETS" (128).

A função de hash deve ser passada no construtor da tabela.

Métodos da classe hash:

```cpp
hashTable(std::function<size_t(key)>)
```
Construtor da classe, recebe uma função de hash como argumento.

```cpp
void insert(key, T)
```
Aplica a função hash na chave "key" e adiciona um valor "T" na tabela.
Caso a chave seja duplicada, a insersão não é realizada de forma silenciosa.

```cpp
T operator[](key)
```
Retorna o valor relacionado a chave. Caso o valor não esteja na tabela, joga a exceção "std::invalid_argument".

```cpp
void remove(key)
```
Remove o valor relacionado a chave. Caso o valor não esteja na tabela, joga a exceção "std::invalid_argument".

```cpp
std::vector<std::tuple<key,T>>* getTable()
```
Retorna o array de vetores utilizado na tabla.

```cpp
size_t getSize()
```
Retorna o número de elementos na tabela.

# main.cpp
Função principal, lê os valores de um arquivo csv e adiciona em uma tabela hash de chave do tipo int e dados do tipo int. Imprime o número de elementos lidos do csv, o número de elementos na tabela e os elementos inseridos na tablela (sem duplicatas). Define uma função hash que tira o módulo da chave pelo número de buckets.

# generate_csv.py
Programa auxiliar que gera 10000 entradas em um arquivo csv, com chaves aleatórias e valores sequenciais de 0 a 9999.

# outros
O arquivo "data.csv" é o arquivo gerado pelo programa auxiliar "generate_csv.py".

O arquivo "dataDuplicates.txt" conta o número de chaves duplicadas em "data.csv".

O arquivo "output.txt" é um exemplo da saída do programa principal.

O arquivo "outputDuplicates.txt" conta o número de chaves duplicadas em "output.txt" (não há duplicatas).
