%% Minutes
x_label = [5	10	15	20	25 30]



%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.42744	0.34136	0.28916	0.25706	0.23288	0.21544]
%y_12 = [0.43222	0.34836	0.29684	0.26444	0.24166	0.22428]
%y_13 = [0.4286	0.33952	0.28588	0.25636	0.23162	0.2144]
%y_14 = [0.4306	0.34158	0.28456	0.2544	0.2269	0.21114]

%E[V_O]
%y_11 = [295.087005	439.28279	524.912469	578.362733	617.20756	644.309301]
%y_12 = [286.283977	429.568681	511.964496	564.79576	602.5566	629.382515]
%y_13 = [300.231795	447.761217	530.115206	583.721471	621.23441	649.445573]
%y_14 = [297.836141	442.843103	530.630403	583.319547	623.422749	652.460742]

%E[V_D]
y_11 = [778.951653	824.238812	853.038905	868.155726	879.313871	886.04608]
y_12 = [773.276892	820.805893	846.368218	862.553733	872.875914	880.344891]
y_13 = [777.912735	827.717485	852.803566	867.866351	880.490975	887.592312]
y_14 = [778.179121	824.663533	856.140117	869.440004	881.778205	890.073749]

i = i+1;
figure(i)

plot(x_label,y_11,'-d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
plot(x_label,y_12,'--s', 'MarkerSize',8, 'LineWidth',1.1)
hold on
plot(x_label,y_13,'--d', 'MarkerSize',8, 'LineWidth',1.1)
hold on
plot(x_label,y_14,'--o', 'MarkerSize',8, 'LineWidth',1.1)
hold on


%ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
ylabel('E[V_D]: MB')
xlabel('B_2 (Unit: Mbps)')


xticklabels({'5',	'10',	'15',	'20',	'25','30'});

												
xlim([5, 30]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'r_2=r_1 (Constant Bandwidth)','r_2=2r_1(Multiple Bandwidth)','r_2=3r_1(Multiple Bandwidth)','r_2=4r_1(Multiple Bandwidth)'},'NumColumns',1);

hold off;
grid on;