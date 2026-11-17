import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)

# four ways to solve this problem:
# 1. employees.head(3) → Best choice for readability and clarity. Returns the first 3 rows.
# 2. employees[:3] → Simple Python slicing. Works based on row position.
# 3. employees.iloc[:3] → Position-based selection using pandas.
# 4. employees.loc[:2] → Label-based selection.