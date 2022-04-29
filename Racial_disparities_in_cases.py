
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Apr 13 11:31:58 2021

@author: nickkalen and kanachiweli
"""
# Nick Kalen and Kanachi Weli

import csv
import matplotlib.pyplot as plt

               
def read_csvfile(filename, name ):
    '''
    Parameters: read csvfile using file and name of state
    Return type: List of string for that statte and titles
    '''
    #open csv file
    with open (filename, "r") as csvfile:
        csv_reader = csv.reader(csvfile , delimiter = ",")
       
        #only save thee rows containing Location in the first position or the name of the state
        for row in csv_reader:
           
            if row[0] == "Location":
                rows_1 = row
               
            elif row[0] ==  name:
                rows_2 = row
               
        #return both lists    
        return [rows_1,rows_2]
           
def clean_row(rows):
    '''
    Parameters: clean csv file using rows
    Return type: remove any NR(Nor reeported or 0 data ), only focus on the
    races individually instead of agregate.
    '''
    #defining the rows
    x_row = rows[1]
    y_row = rows[0]
   
    #defining the list      
    x_list = []
    y_list = []
   
    # a list that iterates over all the provided races / ethnicities
    for i in range(2,8):
        row_x = x_row[i]
       
        #cleans out the O values
        if row_x != '0' :
            x_list.append(row_x)
            row_y = y_row[i]
            y_list.append(row_y)
            #prints the corelations
            print(row_y,":",round((float(row_x)*100),2),"%")
           
        #prints not reported
        else:
          row = y_row[i]
          x = "Not reported"
          print(row, ":",x)
         
    #returns a list  fo graphing      
    return (x_list,y_list)

def include_ethnicity(row):
    '''
    Parameters: search for ethnicity inclusioon
    Return type: alert the reader if the race categories include hispanic"
    '''
    #uses the full list of numbers fro that state
    x_row = row[1]
   
    #at position 2 if it has yes print message
    for i in range(2):
        row = x_row[i]
        if row == "Yes":
            y = "Categories include hispanic"
        else:
            y= "Categories don't include hispanic"
           
    return y

def plot_pie(list, name ):
    '''
    Parameters: plotting pie chart
    Return type: pie chart
    '''
   
    sizes = list[0]
    #create an explode to highlight white vaccination in comparison to other minorities
    explode = []
    for i in range(len(sizes)):
        row = sizes[i]
        if row == sizes[0]:
            row = 0.1
        else:
            row = 0
        explode.append(row)
       
    #plotting the bar graph
    plt.pie(sizes ,shadow=True, labels = list[1], explode = explode,colors = None,pctdistance = 0.8,autopct = '%1.1f%%')
   
    #creating a legend
    plt.legend(prop = {"size":10}, loc = "upper right",bbox_to_anchor = (0.5,1.7))
   
    plt.axis('equal')
    #creating a Title
    plt.title(label = name+"'s Racial and Ethnic disparities in Covid-19 Vaccination", fontsize = 'x-large')
   
    plt.show()
# main function
if __name__ == "__main__":
   
    filename= "raw_data.csv"
    name = input("Enter a state to see the racial disparity in Vacination.\nCase Sensitive (ex Minnesota or North Carolina)\n")
    file = read_csvfile(filename, name)
    clean_rows = clean_row(file)
    plot = plot_pie(clean_rows, name )
    ethnicity = include_ethnicity(file)
    print(ethnicity)
    
    
