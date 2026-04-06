set shell := ["bash", "-uc"]

compile-metziger-my_charybdis:
    qmk compile --compiledb -kb my_charybdis/4x6/v2 -km metziger

flash-metziger-my_charybdis:
    qmk flash -kb my_charybdis/4x6/v2 -km metziger
