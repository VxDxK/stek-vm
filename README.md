# Стёк

### Список команд
##### Манипуляции со стеком
- PUSH n  ( - n ) кладёт число в стек.
- POP (a - ) вынимает из стека одно число, ничего с ним не делает.
- SWAP (a b - b a )
- DUP (a - a a ) вынимает из стека одно число и кладёт его на вершину дважды.
##### Арифметика:
- IADD (a b - [a + b] )
- ISUB (a b - [a - b] ) (обратите внимание на порядок операндов! Сначала кладем в стек то, из чего вычитаем)
- IMUL(a b - [a * b] )
- IDIV (a b - [a / b] )
- IMOD (a b - [a % b] )
- INEG (a - [ -a ] )
##### Чтение и запись
- IPRINT (a - ) вынимает из стека одно число, выводит его на экран.
- IREAD ( - a ) считывает число и кладёт его на стек.
##### Переходы
- JMP
- JZ
##### Прочее
- ICMP (a b - [ if (a < b) then -1; else if (a > b) then 1; else 0 ] )
- STOP

### Cборка и запуск
```
make 
./bin/run
```