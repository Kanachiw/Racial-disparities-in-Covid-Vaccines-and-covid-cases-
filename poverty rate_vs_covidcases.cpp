!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Apr  1 13:04:29 2021

@author: nickkalen and kanachiweli
"""

import csv
import matplotlib.pyplot as plt

# assigns csv files to variables

filename1 = "covid_infections.csv"
filename2 = "poverty_rate.csv"

def read_csv(filename):
    
    """
    Parameters: csv file
    Returns: a list of lists of strings
    Does: reads the csv file row by row, assigns all values a row to a list, 
    appends each row list to a list
    """
    list1 = []
    
# reads csv file row by row, appends each row to list1 as a new list item

    with open(filename, "r") as csvfile:
        csv_reader = csv.reader(csvfile)
    
        for row in csv_reader:
            list1.append(row)
            
    return list1

def state_selection_infection(lst, state):
    
    """
    Parameters: list of rows from csv file
    Returns: list of list of values for each race
    Does: creates lists for each race, appends values from list of lists
    to respective race list based on column, appends race lists to "list_race"
    """
    
# defines variable
    
    list_race = []

# appends list items to specific "list_race"

    for i in range(len(lst)):
        for j in range(len(lst[i])):
            if lst[i][j] == state:
                list_race.append(lst[i][2])
                list_race.append(lst[i][3])
                list_race.append(lst[i][4])
                list_race.append(lst[i][5])
                list_race.append(lst[i][6])
                list_race.append(lst[i][7])
                list_race.append(lst[i][8])
                list_race.append(lst[i][9])
                
    return list_race

def state_selection_poverty(lst, state):
    
    """
    Parameters: list of rows from csv file
    Returns: list of list of values for each race
    Does: creates lists for each race, appends values to "list_poverty"
    """
    
# defines variable
    
    list_poverty = []

# appends list items to specific "list_poverty"

    for i in range(len(lst)):
        for j in range(len(lst[i])):
            if lst[i][j] == state:
                list_poverty.append(lst[i][1])
                list_poverty.append(lst[i][2])
                list_poverty.append(lst[i][3])
                list_poverty.append(lst[i][4])           
    
    return list_poverty
                
def string_to_float(lst):
    
    """
    Parameters: a list strings
    Returns: list of floats
    Does: converts each item in list of lists to float, appends floats to 
    "list_float"
    """

# defines variable
    
    list_float = []
    
# converts list of lists of strings to list of floats
    
    for i in range(len(lst)): 
        list_float.append(float(lst[i]))
    
    return list_float

def infection_percentage(lst)             :
        
    """
    Parameters: list of floats containing % of covid infections and % of 
    population for each race in the chosen state, with % of covid infections 
    occupying odd list positions and % of population in the respective even 
    list position
    Returns: list of floats
    Does: calculated % of covid cases / by % of population for each race,
    appends values to "list_infection"
    """
    
# defines variable
    
    list_infection = []
    
# divides list items to get new values, appends new values and respective
# strings to "list_infection"
    
    list_infection.append(lst[0] / lst[1])
    list_infection.append(lst[2] / lst[3])
    list_infection.append(lst[4] / lst[5])
    list_infection.append(lst[6] / lst[7])
        
    return list_infection

def barplot(lst1, lst2, state):
    
    """
    Parameters: list of floats, list of integers, string input for state
    Returns: a bar plot with 4 bars, poverty rate % as x-axis and Covid
    representation as y-axis
    Does: graphs data by using values from lst2 * 100 for x values and 
    values from lst1 for y values, adds title, legend, and axis titles, 
    changes color and width of bars
    """
    
# plots bar graphs using data from lst1 and lst2, alters bar graph
# width, color, and label
    
    if lst2[0] != 0:
        plt.bar(lst2[0] * 100, lst1[0], color = "blue", width = 1, 
                label = "White")
    else:
        print("No data for White population")
        
    if lst2[1] != 0:
        plt.bar(lst2[1] * 100, lst1[1], color = "red", width = 1, 
                label = "Black")
    else:
        print("No data for Black population")
    if lst2[2] != 0:
        plt.bar(lst2[2] * 100, lst1[2], color = "green", width = 1, 
                label = "Hispanic")
    else:
        print("No data for Hispanic population")
    if lst2[3] != 0:
        plt.bar(lst2[3] * 100, lst1[3], color = "purple", width = 1,
                label = "Asian")
    else: print("No data for Asian population")
        
# creates plot title, creates x and y axis titles, adds legend
    
    plt.title("Representation of Covid Cases vs Poverty Rate by Race in" \
              " {}".format(state))
    plt.xlabel("Poverty Rate % by Race (2019)")
    plt.ylabel("% of Covid Cases / % of Population")   
    plt.legend()

if __name__ == "__main__":
    
# operates functions
    
    infections = read_csv(filename1)
    poverty = read_csv(filename2)
    
# asks user to input the state they want to analyze
    
    state_choice = str(input("Which state would you like to analyze? Sample" \
                             " Input: Alabama\n"))
    print()
    state_data = state_selection_infection(infections, state_choice)
    float_infections = string_to_float(state_data)
    infection_percent = infection_percentage(float_infections)
    poverty_data = state_selection_poverty(poverty, state_choice)
    poverty_float = string_to_float(poverty_data)
    barplot(infection_percent, poverty_float, state_choice)
