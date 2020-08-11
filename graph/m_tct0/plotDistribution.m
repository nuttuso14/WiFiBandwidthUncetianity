%% Minutes
x_label = [0.25	0.5	1	2	4	8]



%% for DeadlinMissRatio

%Miss ratio
%y_11 = [0.5606	0.53235	0.50008	0.47276	0.44605	0.42397]
%y_12 = [0.56865	0.54412	0.52199	0.49564	0.48063	0.46051]
%y_13 = [0.56865	0.54412	0.52199	0.49564	0.48063	0.46051]

%y_12 = [0.56821	0.54265	0.51912	0.49905	0.47771	0.45982]
%y_13 = [0.56821	0.54265	0.51912	0.49905	0.47771	0.45982]


%E[V_O]
%y_11 = [29.191312	40.838535	52.897854	65.052466	76.051461	85.09189]
%y_12 = [26.059646	35.361316	44.361193	53.889261	61.373472	68.45001]
%y_13 = [26.059646	35.361316	44.361193	53.889261	61.373472	68.45001]

%y_12 = [26.128556	35.155575	44.555391	53.655586	62.39603	69.055401]
%y_13 = [26.128556	35.155575	44.555391	53.655586	62.39603	69.055401]


%E[V_D]
y_11 = [170.255487	174.057363	178.606406	183.007296	187.362248	191.519722]
%y_12 = [167.944526	170.93523	174.068954	178.082665	180.52126	183.940697]
%y_13 = [167.944526	170.93523	174.068954	178.082665	180.52126	183.940697]

y_12 = [168.05987	171.386433	174.812617	178.043723	181.525053	184.556691]
y_13 = [168.05987	171.386433	174.812617	178.043723	181.525053	184.556691]


i = i+1;
figure(i)

sz = 80;

semilogx(x_label,y_11,'--', 'MarkerSize',8, 'LineWidth',1.1)
hold on
semilogx(x_label,y_12,'-', 'MarkerSize',8, 'LineWidth',1.1,'color','green')
hold on
scatter(x_label,y_13,sz,'d','red', 'LineWidth',1.3)
hold on
%plot(x_label,y_14,'--o', 'MarkerSize',8, 'LineWidth',1.1)
%hold on


%ylabel('P_{miss}')
%ylabel('Average Offloading Volume (MB)')
ylabel('Average Download Volume (MB)')
xlabel('E[T_C] (Unit: E[T_0])')


xticklabels({'0.25'	,'0.5',	'1'	,'2'	,'4'	,'8'});

												
xlim([0.25, 8]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);
%set(gca,'xticklabel',num2str(get(gca,'XTick')','%.4f'))
%legend({'F=200','F=500','F=1000'},'NumColumns',1);

%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[T_C]'},'NumColumns',1);
%legend({'Constant Bandwidth','Multiple Bandwidth (E[t_1]=E[t_2]=E[t_3])<E[T_C]','Multiple Bandwidth E[t_1]=E[t_2]=E[t_3]=E[T_C]'},'NumColumns',1);

legend({'Sou model (Math.)','Proposed Model (Math.)','Proposed Model (Sim.)'},'NumColumns',1);

hold off;
grid on;