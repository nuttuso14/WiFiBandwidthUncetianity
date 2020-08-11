%% Minutes
x_label = [5	10	15	20	25 30 35]



%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.59665	0.47519	0.38774	0.32703	0.2832	0.24331	0.21605]
%y_12 = [0.63005	0.49468	0.39782	0.33724	0.28832	0.25177	0.22396]
%y_13 = [0.63005	0.49468	0.39782	0.33724	0.28832	0.25177	0.22396]

%y_12 = [0.63783	0.49803	0.39855	0.33215	0.2857	0.24812	0.22095]
%y_13 = [0.63783	0.49803	0.39855	0.33215	0.2857	0.24812	0.22095]



%E[V_O]
%y_11 = [85.142072	64.599316	52.637756	44.333036	38.278622	34.055849	30.466198]
%y_12 = [70.694778	54.021803	44.32808	37.439199	32.873244	29.500626	26.648732]
%y_13 = [70.694778	54.021803	44.32808	37.439199	32.873244	29.500626	26.648732]

%y_12 = [69.495247	53.444328	44.454156	37.730371	32.81938	29.383092	26.706044]
%y_13 = [69.495247	53.444328	44.454156	37.730371	32.81938	29.383092	26.706044]

%E[V_D]
y_11 = [159.496778	182.514299	196.747714	206.080882	212.451723	218.271357	221.898404]
%y_12 = [149.375314	178.177798	195.06631	204.160323	211.465821	216.915929	220.907407]
%y_13 = [149.375314	178.177798	195.06631	204.160323	211.465821	216.915929	220.907407]

y_12 = [148.758119	177.994131	194.97572	205.250661	211.994963	217.309926	221.167376]
y_13 = [148.758119	177.994131	194.97572	205.250661	211.994963	217.309926	221.167376]


i = i+1;
figure(i)

sz = 80;
plot(x_label,y_11,'--', 'LineWidth',1.3)
%scatter(x_label,y_11,sz,'d','green', 'LineWidth',1.3)
hold on
plot(x_label,y_12,'-', 'LineWidth',1.3,'color','green')
%scatter(x_label,y_12,sz2,'s','red', 'LineWidth',1.3)
hold on
%plot(x_label,y_13,'-', 'LineWidth',1.3)
scatter(x_label,y_13,sz,'d','red', 'LineWidth',1.3)
hold on


%ylabel('P_{miss}')
%ylabel('Average Offloading Volume (MB)')
ylabel('Average Download Volume (MB)')
xlabel('B_1 (Unit: Mbps)')


xticklabels({'5',	'10',	'15',	'20',	'25','30', '35'});

												
xlim([5, 30]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);

legend({'Sou model (Math.)','Proposed Model (Math.)','Proposed Model (Sim.)'},'NumColumns',1);

%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[T_C]'},'NumColumns',1);
%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2]=E[t_3])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[t_3]=E[T_C]'},'NumColumns',1);

hold off;
grid on;