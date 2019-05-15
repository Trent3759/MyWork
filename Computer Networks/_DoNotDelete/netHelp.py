
CAL_FUNCTION = """
Format Command as follows:
'Cal <server_address> <principle_in_$> <years_financed> <interest_rate>'

Cal is a loan calculator function that computes
both monthly and yearly payments for a given loan
amount, annual interest rate and loan period.
"""

HELP_FUNCTION = """
Format command as follow:
'help <function_name>'

The command 'help <function>' will provide useful information
on how to use a function if you forget. 
"""
def netHelp(x):
    print({
        'Cal': CAL_FUNCTION,
        'help': HELP_FUNCTION,
    }[x])
