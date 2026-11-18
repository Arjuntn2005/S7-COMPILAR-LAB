# S7 Compiler Lab

Programs completed as part of the S7 Compiler Lab (KTU CSL411). Each folder is one experiment — some are plain C programs, others use LEX and YACC.

## Experiments

| # | Experiment | Folder | Type |
|---|------------|--------|------|
| 1 | Lexical analyzer using C | `Experiment 1` | C |
| 2 | Lexical analyzer using LEX | `Experiment 2` | LEX |
| 3 | Count lines, words and characters | `Experiment 3` | LEX |
| 4 | Convert substring `abc` to `ABC` | `Experiment 4` | LEX |
| 5 | Count vowels and consonants | `Experiment 5` | LEX |
| 6 | Arithmetic expression recognition | `Experiment 6` | LEX + YACC |
| 7 | Identifier recognition | `Experiment 7` | LEX + YACC |
| 8 | Calculator | `Experiment 8` | LEX + YACC |
| 9 | E-closure of all states | `Experiment 9` | C |
| 11 | Shift-reduce parser | `Experiment 11` | C |
| 12 | Code optimization (loop unrolling) | `Experiment 12` | C |
| 13 | Intermediate code generation | `Experiment 13` | C |
| 14 | Assembly/target code generation | `Experiment 14` | C |

> Experiment 10 (First & Follow) is not included — no source was available.

## Requirements

- `gcc`
- `flex` and `bison` (for the LEX / YACC programs)

## How to run

### C programs (1, 9, 11, 12, 13, 14)

```bash
cd "Experiment 1"
gcc expt1.c -o expt1
./expt1
```

Some programs read an input file from the same directory (e.g. `input.c`, `input.dat`, `input.txt`).

### LEX programs (2, 3, 4, 5)

```bash
cd "Experiment 2"
flex expt2.l
gcc lex.yy.c -lfl -o expt2
./expt2
```

### LEX + YACC programs (6, 7, 8)

```bash
cd "Experiment 6"
bison -dy expt6.y
flex expt6.l
gcc lex.yy.c y.tab.c -lfl -o expt6
./expt6
```
