# ✂️ The Boys - Barbershop Management System

Sistema completo de gerenciamento de barbearia com fila em tempo real, múltiplos barbeiros, controle de pagamentos e relatórios.

## 🎯 Features

- ✅ **Login/Autenticação** com JWT
- ✅ **2 Interfaces**: Barbeiro (atendimento) + Gerente (controle total)
- ✅ **Fila em Tempo Real** com múltiplos barbeiros simultâneos
- ✅ **Cadastro de Clientes** com histórico
- ✅ **Serviços com Preços Variáveis**
- ✅ **Processamento de Pagamentos** (Dinheiro/Cartão)
- ✅ **Dashboard** com estatísticas do dia
- ✅ **Relatórios e Analytics**
- ✅ **Exportação de Dados** em CSV

---

## 🚀 Quick Start

### Pré-requisitos
- Python 3.8+
- Node.js 16+
- pip (Python package manager)
- npm (Node package manager)

### Backend (Python + Flask)

```bash
# 1. Entrar na pasta do backend
cd backend

# 2. Criar ambiente virtual
python -m venv venv
source venv/bin/activate  # Linux/Mac
# ou
venv\Scripts\activate     # Windows

# 3. Instalar dependências
pip install -r requirements.txt

# 4. Criar usuários de teste (opcional - criar em um script)
# Por enquanto, use a API para registrar

# 5. Rodar servidor
python app.py
```

O backend rodará em `http://localhost:5000`

### Frontend (React + Vite)

```bash
# 1. Entrar na pasta do frontend (em outro terminal)
cd frontend

# 2. Instalar dependências
npm install

# 3. Rodar desenvolvimento
npm run dev
```

O frontend rodará em `http://localhost:3000`

---

## 📝 Primeiros Passos

### 1. Criar Usuário Manager (Gerente)

**POST** `http://localhost:5000/api/auth/register`
```json
{
  "username": "admin",
  "password": "admin",
  "role": "manager"
}
```

### 2. Login no Frontend

- Acesse `http://localhost:3000`
- Faça login com: `admin` / `admin`
- Você será direcionado para o dashboard do gerente

### 3. Criar Barbeiros

Na aba **"Barbeiros"** do dashboard:
- Clique em "+ Novo Barbeiro"
- Preencha nome de usuário e senha
- Clique em "Criar Barbeiro"

### 4. Criar Serviços

Na aba **"Serviços"**:
- Clique em "+ Novo Serviço"
- Digite o nome (ex: "Corte Simples") e preço (ex: 30.00)
- Clique em "Criar Serviço"

### 5. Cadastrar Clientes

Na aba **"Clientes"**:
- Clique em "+ Novo Cliente"
- Preencha nome e telefone
- Clique em "Criar Cliente"

### 6. Iniciar Fila

Na aba **"Fila"**:
- (Será preenchida quando clientes forem adicionados)

---

## 🏗️ Arquitetura

### Backend (Python/Flask)

```
backend/
├── app.py                 # Aplicação principal
├── models.py             # Modelos do banco de dados
├── routes_auth.py        # Autenticação
├── routes_barbers.py     # Gerenciamento de barbeiros
├── routes_clients.py     # Gerenciamento de clientes
├── routes_services.py    # Gerenciamento de serviços
├── routes_queue.py       # Fila de atendimento
├── routes_payments.py    # Processamento de pagamentos
├── routes_analytics.py   # Relatórios e estatísticas
├── requirements.txt      # Dependências Python
└── README.md            # Documentação
```

### Frontend (React/Vite)

```
frontend/
├── index.html            # HTML base
├── package.json          # Dependências NPM
├── vite.config.js       # Config do Vite
└── src/
    ├── main.jsx         # Entry point
    ├── App.jsx          # Roteamento
    ├── App.css          # Estilos globais
    ├── api.js           # Cliente HTTP
    ├── pages/
    │   ├── Login.jsx    # Página de login
    │   ├── BarberDashboard.jsx    # Interface do barbeiro
    │   └── ManagerDashboard.jsx   # Interface do gerente
    └── components/
        ├── ManagerOverview.jsx
        ├── ClientsTab.jsx
        ├── ServicesTab.jsx
        ├── QueueTab.jsx
        ├── BarbersTab.jsx
        ├── PaymentsTab.jsx
        └── ReportsTab.jsx
```

---

## 📚 API Endpoints

### Autenticação
- `POST /api/auth/register` - Registrar
- `POST /api/auth/login` - Login
- `GET /api/auth/me` - Dados do usuário

### Barbeiros (Manager)
- `GET /api/barbers` - Listar
- `POST /api/barbers` - Criar
- `DELETE /api/barbers/<id>` - Deletar

### Clientes
- `GET /api/clients` - Listar
- `POST /api/clients` - Criar
- `GET /api/clients/<id>` - Detalhes
- `PUT /api/clients/<id>` - Atualizar
- `GET /api/clients/<id>/history` - Histórico

### Serviços (Manager)
- `GET /api/services` - Listar
- `POST /api/services` - Criar
- `PUT /api/services/<id>` - Atualizar
- `DELETE /api/services/<id>` - Deletar

### Fila
- `GET /api/queue` - Ver fila
- `POST /api/queue` - Adicionar
- `PUT /api/queue/<id>/start` - Iniciar atendimento
- `PUT /api/queue/<id>/complete` - Finalizar
- `PUT /api/queue/<id>/cancel` - Cancelar

### Pagamentos (Manager)
- `GET /api/payments` - Listar
- `PUT /api/payments/<id>/process` - Processar
- `PUT /api/payments/<id>/cancel` - Cancelar
- `GET /api/payments/pending` - Pendentes

### Analytics (Manager)
- `GET /api/analytics/dashboard` - Dashboard
- `GET /api/analytics/barber/<id>/stats` - Stats do barbeiro
- `GET /api/analytics/revenue` - Receita
- `GET /api/analytics/export` - Exportar dados

---

## 🎨 Interface do Barbeiro

O barbeiro vê:
- **Cliente em Atendimento**: Dados do cliente e serviço
- **Fila de Espera**: Próximos clientes em ordem
- **Estatísticas do Dia**: Serviços completados, tempo médio, receita

Ações:
- Clicar "Atender" para iniciar atendimento
- Clicar "Finalizar Serviço" após completar

---

## 🎨 Interface do Gerente

O gerente acessa:
- **Visão Geral**: Dashboard com métricas principais
- **Fila**: Controle total (pode cancelar)
- **Clientes**: Cadastro e histórico
- **Serviços**: CRUD de serviços
- **Barbeiros**: Criar/deletar barbeiros
- **Pagamentos**: Processar pagamentos pendentes
- **Relatórios**: Analytics e exportação de dados

---

## 💾 Banco de Dados

Por padrão, usa SQLite (`theboys.db`). Para trocar para PostgreSQL:

1. Instale: `pip install psycopg2-binary`
2. Configure em `.env`:
   ```
   DATABASE_URL=postgresql://user:password@localhost:5432/theboys
   ```

---

## 🔒 Segurança (Produção)

Antes de usar em produção:

1. Mude a `JWT_SECRET_KEY` em `.env`
2. Use HTTPS
3. Configure CORS corretamente
4. Use banco de dados robusto (PostgreSQL)
5. Implemente rate limiting
6. Adicione validação adicional

---

## 📦 Deploy

### Backend (Heroku/Render/Railway)

```bash
# Criar Procfile
echo "web: gunicorn app:app" > Procfile

# Instalar gunicorn
pip install gunicorn

# Deploy
git push heroku main
```

### Frontend (Vercel/Netlify)

```bash
npm run build
# Fazer upload da pasta 'dist' para Vercel/Netlify
```

---

## 🐛 Troubleshooting

### "Connection refused" na porta 5000
- Backend não está rodando. Execute `python app.py` no terminal do backend

### "CORS error"
- Certifique-se que o backend está rodando em `http://localhost:5000`
- Configure CORS corretamente no `app.py`

### Banco de dados vazio
- Crie usuários via API ou adicione seed data

---

## 📞 Contato

Qualquer dúvida, abra uma issue no repositório!

---

**Versão**: 1.0.0  
**Última atualização**: 2025-03-28
