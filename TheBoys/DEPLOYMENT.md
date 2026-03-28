# 🚀 GUIA DE DEPLOYMENT - THE BOYS

## OPÇÃO 1: Deploy na Heroku (Backend)

### Pré-requisitos
- Conta no Heroku (heroku.com)
- Git instalado
- Heroku CLI instalado

### Passo a passo

1. **Fazer login no Heroku**
```bash
heroku login
```

2. **Criar aplicação no Heroku**
```bash
cd backend
heroku create the-boys-api
```

3. **Adicionar Procfile**
```
web: gunicorn app:app
```

4. **Instalar dependências**
```bash
pip install gunicorn
pip freeze > requirements.txt
```

5. **Fazer deploy**
```bash
git push heroku main
```

6. **Configurar variáveis de ambiente**
```bash
heroku config:set JWT_SECRET_KEY=seu_secret_key_seguro
heroku config:set DATABASE_URL=postgresql://...
```

7. **Criar banco de dados (Heroku Postgres)**
```bash
heroku addons:create heroku-postgresql:hobby-dev
```

---

## OPÇÃO 2: Deploy na Railway (Recomendado)

### Pré-requisitos
- Conta no Railway (railway.app)
- GitHub conectado

### Backend

1. **Push para GitHub**
```bash
git add .
git commit -m "Deploy to Railway"
git push origin main
```

2. **Conectar no Railway**
   - Ir para railway.app
   - Click "New Project"
   - Selecionar repositório GitHub
   - Escolher diretório: `backend`

3. **Configurar variáveis de ambiente**
   - DATABASE_URL: Usar Railway Postgres
   - JWT_SECRET_KEY: Secret seguro
   - FLASK_ENV: production

4. **Deploy automático**
   - Railway faz deploy automático a cada push

---

## OPÇÃO 3: Deploy em VPS (DigitalOcean/Linode)

### Setup Backend

1. **Conectar via SSH**
```bash
ssh root@seu_vps_ip
```

2. **Instalar dependências**
```bash
apt update && apt upgrade -y
apt install python3-pip python3-venv postgresql nginx -y
```

3. **Clonar repositório**
```bash
git clone seu_repositorio.git
cd the-boys/backend
```

4. **Criar ambiente virtual**
```bash
python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
pip install gunicorn
```

5. **Configurar banco PostgreSQL**
```bash
sudo -u postgres psql
CREATE DATABASE theboys;
CREATE USER theboys WITH PASSWORD 'sua_senha';
ALTER ROLE theboys SET client_encoding TO 'utf8';
GRANT ALL PRIVILEGES ON DATABASE theboys TO theboys;
```

6. **Criar arquivo systemd service**
```bash
sudo nano /etc/systemd/system/theboys-api.service
```

Adicionar:
```ini
[Unit]
Description=The Boys API
After=network.target

[Service]
User=www-data
WorkingDirectory=/var/www/the-boys/backend
Environment="PATH=/var/www/the-boys/backend/venv/bin"
ExecStart=/var/www/the-boys/backend/venv/bin/gunicorn -w 4 -b 0.0.0.0:5000 app:app

[Install]
WantedBy=multi-user.target
```

7. **Ativar serviço**
```bash
sudo systemctl daemon-reload
sudo systemctl start theboys-api
sudo systemctl enable theboys-api
```

8. **Configurar Nginx**
```bash
sudo nano /etc/nginx/sites-available/the-boys
```

Adicionar:
```nginx
server {
    listen 80;
    server_name seu_dominio.com;

    location / {
        proxy_pass http://127.0.0.1:5000;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }

    location /socket.io {
        proxy_pass http://127.0.0.1:5000/socket.io;
        proxy_http_version 1.1;
        proxy_buffering off;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection "upgrade";
    }
}
```

9. **Ativar site**
```bash
sudo ln -s /etc/nginx/sites-available/the-boys /etc/nginx/sites-enabled/
sudo systemctl restart nginx
```

10. **SSL com Let's Encrypt**
```bash
sudo apt install certbot python3-certbot-nginx -y
sudo certbot --nginx -d seu_dominio.com
```

---

## Frontend - Vercel (Recomendado)

1. **Push para GitHub**
```bash
git push origin main
```

2. **Conectar em Vercel**
   - Ir para vercel.com
   - Importar projeto do GitHub
   - Configurar:
     - Framework: Vite
     - Build Command: `npm run build`
     - Output Directory: `dist`

3. **Variáveis de ambiente**
   - VITE_API_URL: https://seu-backend.com

4. **Deploy automático**
   - Cada push dispara novo deploy

---

## Frontend - Netlify

1. **Build local**
```bash
cd frontend
npm run build
```

2. **Deploy com Netlify CLI**
```bash
npm install -g netlify-cli
netlify deploy --prod --dir=dist
```

Ou via GitHub:
- Conectar repositório em netlify.com
- Configurar build settings
- Deploy automático a cada push

---

## Configuração de Domínio

### Apontar domínio

1. **DNS Provider (GoDaddy, Cloudflare, etc)**
   - Backend: Apontar A record para IP do VPS/Heroku
   - Frontend: Usar nameservers do Vercel/Netlify

2. **HTTPS**
   - Heroku/Railway: Automático
   - VPS: Usar Let's Encrypt (certbot)
   - Vercel/Netlify: Automático

---

## Checklist de Produção

- [ ] Mudar `DEBUG=False` no Flask
- [ ] Usar banco PostgreSQL (não SQLite)
- [ ] Configurar JWT_SECRET_KEY seguro
- [ ] CORS configurado apenas para seu domínio
- [ ] Backup automático ativado
- [ ] Logs configurados
- [ ] Email para erros críticos
- [ ] Rate limiting ativado
- [ ] HTTPS/SSL configurado
- [ ] Teste de carga realizado

---

## Monitoramento

### Logs

**Heroku:**
```bash
heroku logs -t
```

**VPS (Systemd):**
```bash
sudo journalctl -u theboys-api -f
```

### Health Check

```bash
curl https://seu_api.com/api/auth/me
```

### Backup Automático

```bash
# No VPS, adicionar ao crontab
0 2 * * * cd /var/www/the-boys/backend && python backup_database.py --export-json && python backup_database.py --clean 30
```

---

## Troubleshooting

### Erro 503 (Service Unavailable)
- Reiniciar aplicação
- Verificar logs
- Aumentar timeout

### Erro de conexão ao banco
- Verificar DATABASE_URL
- Testar conexão: `psql $DATABASE_URL`

### Página em branco (Frontend)
- Verificar console do navegador
- Verificar VITE_API_URL
- Verificar CORS no backend

### WebSockets não funcionam
- Verificar proxy do Nginx
- Adicionar cabeçalhos Upgrade/Connection
- Testar com `wscat` ou Postman

---

## Custos Estimados (mensais)

| Serviço | Plano | Preço |
|---------|-------|-------|
| Railway | Starter | $5-20 |
| Heroku | Standard | $50+ |
| DigitalOcean VPS | Básico | $5-10 |
| Vercel | Free/Pro | $0-20 |
| Netlify | Free | $0 |
| **Total mínimo** | | **$5-10** |

---

## Próximos Passos

1. Escolher plataforma de deployment
2. Configurar variáveis de ambiente
3. Executar migrations do banco
4. Testar em staging
5. Fazer deploy em produção
6. Configurar monitoring e alertas
7. Documentar processo
