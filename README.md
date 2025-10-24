# Todo App (Flask)

A minimal Flask application with user sign-up/login and a personal todo list.

## Features
- Secure sign-up and login using password hashing
- Create, toggle complete, and delete todos
- Per-user data isolation (SQLite)
- Simple, modern UI

## Requirements
- Python 3.10+
- `python3-venv` and `python3-pip` installed

## Quickstart

```bash
# 1) Create and activate virtual environment
python3 -m venv .venv
source .venv/bin/activate

# 2) Install dependencies
pip install -r requirements.txt

# 3) Run the app
python app/app.py
# Visit http://localhost:5000
```

Set `SECRET_KEY` to a strong value in the environment for production:

```bash
export SECRET_KEY="change-me-to-a-random-string"
```

## Project Structure

```
app/
  app.py
  __init__.py
  templates/
    base.html
    login.html
    signup.html
    todos.html
  static/
    style.css
requirements.txt
```
