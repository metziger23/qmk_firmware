set shell := ["bash", "-uc"]

compile-metziger-my_charybdis:
    source ~/qmk-venv/bin/activate ; qmk compile -kb my_charybdis/4x6/v2 -km metziger

flash-metziger-my_charybdis:
    source ~/qmk-venv/bin/activate ; qmk flash -kb my_charybdis/4x6/v2 -km metziger

generate-compilation-database-metziger-my_charybdis:
    source ~/qmk-venv/bin/activate ; qmk generate-compilation-database -kb my_charybdis/4x6/v2 -km metziger
