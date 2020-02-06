%% File size
%N=10000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	20	21	22	23	24	26]
%N=50000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	26	27	29]
%N=100000
%x_label =[0.5	1	1.5	2	2.5	3	3.5	4	4.5	5	5.5	6	6.5	7	7.5	8	8.5	9	9.5	10]

x_label =[0.5	1	1.5	2	2.5	3	3.5	4]


%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.1557	0.279	0.3953	0.4746	0.5699	0.6286	0.6848	0.7346]
%y_12 = [0.1739	0.3142	0.4229	0.5279	0.6122	0.6771	0.7358	0.7864]


%E[V_O]
%y_11 = [228.528879	400.120899	539.378211	669.862525	762.362137	857.161862	931.069984	990.566782]
%y_12 = [164.897881	301.036203	418.369524	511.658631	582.912938	648.569348	702.970377	738.326107]

%E[V_D]
y_11 = [459.04761	854.16907	1176.233434	1473.678343	1689.704782	1906.151861	2077.260088	2212.828817]
y_12 = [455.437678	829.877077	1153.459785	1409.136801	1605.287463	1785.645372	1935.648532	2033.694117]


i = i+1;
figure(i)

plot(x_label,y_11,'-x', 'MarkerSize',10, 'LineWidth',1.3)
hold on
plot(x_label,y_12,'-s', 'MarkerSize',10, 'LineWidth',1.3)
hold on
%plot(x_label,y_21,'-+', 'MarkerSize',10, 'LineWidth',1.3)
%hold on
%plot(x_label,y_22,'-^', 'MarkerSize',10, 'LineWidth',1.3)
%hold on
%plot(x_label,y_31,'-d', 'MarkerSize',10, 'LineWidth',1.3)
%hold on
%plot(x_label,y_32,'-o', 'MarkerSize',10, 'LineWidth',1.3)
%hold on

%ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
ylabel('E[V_D]: MB')
%xlabel('E[t_0]:')
xlabel('File size: GB')

%xticklabels({'62.5','125','250','500','1000','2000','4000','8000'});
%xticklabels({'10','20','40','80','160','320','640','1280'});
%xticklabels({'50','100','150','200','250','300','350','400'});
%xticklabels({'1',	'0.5',	'0.2',	'0.1',	'0.05',	'0.025',	'0.016666667',	'0.008333333',	'0.006666667',	'0.003333333',	'0.001666667'	,'0.000833333',	'0.000416667'});
xticklabels({'0.5',	'1',	'1.5',	'2',	'2.5',	'3',	'3.5',	'4'});




												
xlim([0.5, 4]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'Smooth connection','Unstable Connection'},'NumColumns',1);

hold off;
grid on;