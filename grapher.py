import matplotlib.pyplot as plt

array_sizes = [1,5,10,20,50,100,250,500,750,1000]

add_array = [0.0276, 0.0794, 0.1646, 0.2614, 0.7654, 1.2808, 2.7172, 4.9552, 7.534, 11.22]
delete_array = [0.0154, 0.083, 0.1492, 0.2548, 0.7614, 1.3146, 2.8312, 5.8292, 8.123, 10.8022]
update_array = [0.0066, 0.0116, 0.0306, 0.032, 0.0968, 0.1554, 0.311, 0.6548, 0.899, 1.2192]

add_file = [0.492, 0.668, 0.831, 0.719, 0.568, 0.557, 0.559, 0.437, 0.537, 0.512]
delete_file = [0.532, 3.71, 4.93, 9.649, 20.08, 36.61, 79.309, 154.628, 210.245, 283.312]
update_file = [0.575, 4.32, 7.23, 12.329, 25.438, 48.865, 99.324, 199.342, 300.234, 390.352]

add_vector = [0.001, 0.004, 0.002, 0.003, 0.001, 0.001, 0.002, 0.002, 0.001, 0.002]
delete_vector = [0.016, 0.052, 0.103, 0.208, 0.458, 0.907, 2.115, 4.258, 6.342, 8.344]
update_vector = [0.013, 0.078, 0.136, 0.244, 0.56, 1.093, 2.688, 4.398, 6.813, 9.417]

add_list = [0.002, 0.003, 0.002, 0.003, 0.002, 0.002, 0.002, 0.002, 0.002, 0.002]
delete_list = [0.003, 0.067, 0.125, 0.189, 0.556, 1.08, 2.355, 4.78, 6.634, 8.185]
update_list = [0.017, 0.071, 0.151, 0.324, 0.499, 0.966, 2.279, 4.562, 7.234, 10.563]

add_ll = [0.001, 0.006, 0.004, 0.003, 0.004, 0.004, 0.003, 0.003, 0.002, 0.003]
delete_ll = [0.005, 0.032, 0.04, 0.051, 0.271, 0.395, 0.811, 1.708, 2.682, 3.542]
update_ll = [0.014, 0.042, 0.051, 0.162, 0.197, 0.304, 0.782, 1.581, 3.539, 5.791]

add_bst = [0.003, 0.004, 0.003, 0.004, 0.004, 0.003, 0.005, 0.004, 0.004, 0.005]
delete_bst = [0.001, 0.002, 0.003, 0.004, 0.003, 0.005, 0.004, 0.003, 0.004, 0.004]
update_bst = [0.002, 0.004, 0.005, 0.006, 0.004, 0.003, 0.005, 0.005, 0.004, 0.005]

add_map = [0.003, 0.004, 0.003, 0.004, 0.005, 0.003, 0.005, 0.004, 0.003, 0.004]
delete_map = [0.001, 0.003, 0.003, 0.003, 0.003, 0.002, 0.004, 0.003, 0.004, 0.004]
update_map = [0.005, 0.005, 0.005, 0.004, 0.006, 0.003, 0.005, 0.004, 0.004, 0.005]

add_sl = [0.004, 0.004, 0.005, 0.005, 0.005, 0.005, 0.006, 0.007, 0.007, 0.007]
delete_sl = [0.003, 0.005, 0.004, 0.004, 0.004, 0.004, 0.005, 0.006, 0.005, 0.006]
update_sl = [0.006, 0.005, 0.006, 0.006, 0.005, 0.006, 0.006, 0.004, 0.007, 0.005]

# Plotting ADD operation
plt.figure(figsize=(10, 6))

# plt.subplot(1, 3, 1)
# plt.plot(array_sizes, add_bst, '-o', label='Binary Tree')
# plt.plot(array_sizes, add_map, '-d', label='Map')
# plt.plot(array_sizes, add_list, '-s', label='Skip List')
# plt.xlabel('Data Size (x1000)')
# plt.ylabel('Measured Time (ms)')
# plt.title('ADD Operation (Group 3)')
# plt.legend()

# Plotting DELETE operation
# plt.subplot(1, 3, 2)
plt.plot(array_sizes, add_bst, '-o', label='Binary Tree')
plt.plot(array_sizes, add_map, '-d', label='Map')
plt.plot(array_sizes, add_sl, '-s', label='Skip List')
plt.xlabel('Data Size (x1000)')
plt.ylabel('Measured Time (ms)')
plt.title('ADD Operation (Group 3)')
plt.legend()

# Plotting UPDATE operation
# plt.subplot(1, 3, 3)
# plt.plot(array_sizes, update_bst, '-o', label='Binary Tree')
# plt.plot(array_sizes, update_map, '-d', label='Map')
# plt.plot(array_sizes, update_sl, '-s', label='Skip List')
# plt.xlabel('Data Size (x1000)')
# plt.ylabel('Measured Time (ms)')
# plt.title('UPDATE Operation (Group 3)')
# plt.legend()

plt.tight_layout()
plt.show()