# Read in data from file
with open('intercepts.txt', 'r') as datafile:
  buf = datafile.read().replace('\n', ' ')
  keys = buf.split()

# Find 3 conjugates
for i in range(0,3): 
  # Setup initial conjugate values from first key
  cycle = [[]]
  perm_num = 0
  cycle[perm_num].append(keys[i][i])
  cycle[perm_num].append(keys[i][i+3]) 
  
  # loop until cycle is correct length
  cycle_len = 2
  while (cycle_len < 26):
    #print(cycle)
    for key in keys:
      if (key[i] == cycle[perm_num][-1]):
        # Check if we have found end of one permutation
        if (key[i+3] == cycle[perm_num][0]):
          #print(cycle[perm_num])
          
          # find new start for next perm
          cont = True
          use = True
          for k in keys:
            if cont:
              for perm in cycle:
                if k[i] in perm:
                  use = False

              # Start new permutation
              if use:
                perm_num += 1
                cycle.append([])  
                cycle[perm_num].append(k[i])
                cycle[perm_num].append(k[i+3])
                cycle_len += 2
                cont = False
              else:
                use = True
                
         
          break
        else:
          cycle[perm_num].append(key[i+3])
          cycle_len += 1 
        break
  
  cycle_str = ""
  for perm in cycle:
    cycle_str +='(' + '\ '.join(perm) + ')' 

  print(cycle_str)








