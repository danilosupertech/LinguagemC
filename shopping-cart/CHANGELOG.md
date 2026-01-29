# CHANGELOG

Todas as mudanças notáveis neste projeto serão documentadas neste arquivo.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/pt-BR/),
e este projeto segue [Semantic Versioning](https://semver.org/lang/pt-BR/).

---

## [2.0] - 2026-01-29

### ✨ Adicionado

- **Modularização Completa**: Separação clara entre header (`shopping_cart.h`) e implementação (`shopping_cart.c`)
- **Documentação Doxygen**: Todos os tipos, funções e estruturas documentados
- **Interface Robusta**: Sistema de retorno de erros com enum `CartStatus`
- **Menu Interativo Profissional**: Interface CLI com menus formatados com bordas
- **Exemplo de Aplicação**: `main.c` com todas as funcionalidades demonstradas
- **Arquivo de Exemplos**: `examples.c` com 7 exemplos diferentes de uso
- **Build System**: Makefile com múltiplos targets (build, run, debug, clean, etc.)
- **README Completo**: Documentação extensiva com:
  - Visão geral detalhada
  - Referência completa da API
  - Exemplos de código
  - Padrões de tratamento de erros
  - Análise de complexidade computacional
  - Possíveis melhorias futuras

### 🔧 Melhorado

- **Tratamento de Memória**: Eliminado uso de `strcpy` (inseguro) em favor de `strncpy`
- **Validação de Entrada**: Todos os inputs validados antes de processamento
- **Estrutura de Dados**: Adicionado campo `item_count` para rastreamento eficiente
- **Interface do Usuário**: Mensagens de feedback com ícones (✓, ✗) para melhor UX
- **Tratamento de Strings**: Proteção contra buffer overflow
- **Compilação Segura**: Flags `-Wall -Wextra -pedantic` habilitadas
- **Formatação de Tabelas**: Uso de caracteres Unicode para bordas mais profissionais

### 🗑️ Removido

- Código de exemplo simples (substituído por exemplos mais robustos)
- Documentação incompleta (substituída por README completo)

### 🐛 Corrigido

- Risco de buffer overflow em `strcpy`
- Falta de validação de entrada
- Documentação inadequada
- Falta de tratamento de erros consistente

### 📊 Métricas de Qualidade

| Métrica | Valor |
|---------|-------|
| Linhas de Código | ~800 |
| Funções Públicas | 10 |
| Estruturas | 3 (CartStatus, Product, ShoppingCart) |
| Cobertura de Documentação | 100% |
| Flags de Compilação Segura | -Wall -Wextra -pedantic -std=c99 |

---

## [1.0] - (Histórico)

### ✨ Adicionado (Versão Original)

- Estrutura `Carrinho` simples
- Funções básicas (adicionar, listar, liberar)
- Exemplo de uso hardcoded no `main()`
- Suporte a lista encadeada

### ⚠️ Limitações da Versão 1.0

- Sem separação de módulos
- Sem documentação adequada
- Sem tratamento de erros
- Interface limitada
- Sem validação de entrada
- Risco de segurança em manipulação de strings

---

## Plano Futuro (Roadmap)

### Versão 3.0 (Planejado)

- [ ] Persistência em arquivo (salvar/carregar carrinho)
- [ ] Suporte a múltiplas moedas
- [ ] Sistema de descontos automáticos
- [ ] Histórico de operações (undo/redo)
- [ ] Categorização de produtos
- [ ] Índices para busca mais rápida

### Versão 4.0 (Proposto)

- [ ] Interface gráfica (GTK+ ou Qt)
- [ ] API REST para integração
- [ ] Banco de dados SQLite
- [ ] Sistema de usuários
- [ ] Relatórios e análises

---

## Como Contribuir

Se você deseja contribuir para este projeto:

1. Faça um fork do repositório
2. Crie uma branch para sua feature (`git checkout -b feature/AmazingFeature`)
3. Commit suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. Push para a branch (`git push origin feature/AmazingFeature`)
5. Abra um Pull Request

---

## Notas de Release

### v2.0 - Modernização Profissional

Esta versão representa uma completa modernização do código original, seguindo padrões profissionais de desenvolvimento em C:

✅ **Qualidade**: Código seguro e bem documentado  
✅ **Usabilidade**: Interface intuitiva e responsiva  
✅ **Manutenibilidade**: Estrutura clara e modular  
✅ **Escalabilidade**: Preparado para futuras expansões  

**Breaking Changes**: Nenhum (novo projeto)

**Instruções de Upgrade**: Não aplicável

---

## Autores e Créditos

- **Desenvolvedor Principal**: Danilo Côrtes Gonçalves

---

## Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo LICENSE para detalhes.
