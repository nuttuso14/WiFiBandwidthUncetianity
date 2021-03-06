%% File size
%N=10000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	20	21	22	23	24	26]
%N=50000
%x_label =[0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15	16	17	18	19	20	21	22	23	24	26	27	29]
%N=100000
%x_label =[0.5	1	1.5	2	2.5	3	3.5	4	4.5	5	5.5	6	6.5	7	7.5	8	8.5	9	9.5	10]

x_label =[50	100 150	200	250	300	350	400	450	500]


%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.1187	0.2122 0.2914	0.374	0.4319	0.4965	0.547	0.5953	0.6329	0.675]
%y_12 = [0.134	0.2408 0.3275	0.4156	0.489	0.5458	0.5854	0.6453	0.6906	0.7228]


%E[V_O]
%y_11 = [28.4992	53.360134	71.686883	85.518683	98.801433	108.882912	118.635038	127.311763	135.569304	140.588153]
%y_12 = [16.843317	31.928299	45.041325	55.64652	65.631273	75.533678	84.45847	89.864795	95.937327	101.864134]

%E[V_D]
y_11 = [46.828979	88.323299	126.108097	159.123858	190.35086	216.768955	240.356971	262.380596	283.079487	298.29094]
y_12 = [46.356285	87.074119	123.433792	153.435288	181.077434	206.915727	231.804479	247.454677	265.663031	280.095683]


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
xlabel('File size: MB')

%xticklabels({'62.5','125','250','500','1000','2000','4000','8000'});
%xticklabels({'10','20','40','80','160','320','640','1280'});
%xticklabels({'50','100','150','200','250','300','350','400'});
%xticklabels({'1',	'0.5',	'0.2',	'0.1',	'0.05',	'0.025',	'0.016666667',	'0.008333333',	'0.006666667',	'0.003333333',	'0.001666667'	,'0.000833333',	'0.000416667'});
xticklabels({'50',	'100','150',	'200',	'250',	'300',	'350',	'400',	'450',	'500'});



												
xlim([50, 500]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);
legend({'Smooth connection','Unstable Connection'},'NumColumns',1);

hold off;
grid on;