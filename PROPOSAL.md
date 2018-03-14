# Trading Platform

## Overview

The goal is to design and implement a fully functional trading platform that ultimately allows users to buy and sell certain assets. The platform should be able to execute trades efficiently and correctly.

## Distributed Computing Considerations

## Proposed Features

### Accounts

Users should be able to create accounts. These accounts should be able to maintain certain attributes, such as portfolios and trade history, and perform certain actions such as submitting a trade order. These are listed in greater detail below. The server should be able to track and handle all these features.

#### Attributes
- Portfolio
	- Assets
		- Purchase price
		- Current price
		- Quantity
		- Change
	- Cash/liquid assets
	- Trade history
- Account settings (i.e login, password)

#### Actions
- Buy order
- Sell order
- Deposit
- Withdrawal
- Create portfolio
- Delete portfolio
- Switch portfolio
- Change account settings (i.e password)

### Execution

The server should maintain a list of bids and asks for each tradeable asset and execute accordingly.

## Specifications and Technologies

