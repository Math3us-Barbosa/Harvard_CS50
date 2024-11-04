import re

patterns = {
    "AMEX": r"^3[47][0-9]{13}$",          # Começa com 34 ou 37, e tem 15 dígitos
    "VISA": r"^4[0-9]{12}(?:[0-9]{3})?$", # Começa com 4, e tem 13 ou 16 dígitos
    "MASTERCARD": r"^5[1-5][0-9]{14}$"    # Começa com 51-55, e tem 16 dígitos
}
