import decimal
from decimal import Decimal, getcontext


def gauss_legendre_pi(precision):
    # Set precision for decimal calculations
    getcontext().prec = (
        precision + 2
    )  # Set precision slightly higher to avoid rounding issues

    # Initialize variables
    a = Decimal(1)
    b = Decimal(1) / Decimal(2).sqrt()
    t = Decimal(1) / Decimal(4)
    p = Decimal(1)

    # Gauss-Legendre iterations
    for _ in range(
        precision.bit_length()
    ):  # Approximation of the number of iterations needed
        a_next = (a + b) / 2
        b = (a * b).sqrt()
        t -= p * (a - a_next) * (a - a_next)
        a = a_next
        p *= 2

    # Calculate Pi: pi = (a + b)^2 / (4 * t)
    pi = (a + b) * (a + b) / (4 * t)

    return pi


def print_pi(digits):
    # Call the Gauss-Legendre algorithm with the required precision
    pi = gauss_legendre_pi(digits)

    # Print Pi with the required number of digits
    # Convert to string to print it to the desired number of digits
    pi_str = str(pi)[: digits + 2]  # +2 for "3." at the beginning
    print(pi_str)


# Example: Print 1000 digits of Pi
if __name__ == "__main__":
    digits_to_print = 10000  # Change this to your desired number of digits
    print_pi(digits_to_print)
