%% Minutes
x_label =[0.5	1	2	4	8]

color_table = [0 0 1 ; 1 0 0 ;0 0 1 ; 1 0 0 ;0 0 1 ; 1 0 0 ;];
marker_table = ["d","s","d","s","d","s"];
line_style_table = ["-","--","-","--","-","--"];

%% for DeadlinMissRatio

%Miss ratio
y_11 = [0.63548	0.63812	0.63942	0.63922	0.63476]
y_12 = [0.63748	0.63936	0.6403	0.64458	0.6473]
y_13 = [0.56732	0.56486	0.56684	0.56594	0.56698]
y_14 = [0.56506	0.57064	0.57866	0.5832	0.58334]
y_15 = [0.4772	0.47782	0.47648	0.47798	0.48002]
y_16 = [0.48196	0.49056	0.49984	0.50084	0.50508]

%E[V_O]
%y_11 = [14.628009	14.597173	14.564124	14.570459	14.766825]
%y_12 = [14.778362	14.368566	13.830503	13.339943	13.243097]
%y_13 = [24.387005	24.401581	24.366436	24.408788	24.357839]
%y_14 = [24.372917	23.49777	22.458167	21.981896	21.804793]
%y_15 = [36.279782	35.977783	36.090629	36.077711	35.922807]
%y_16 = [35.2173	34.135006	32.713678	32.466591	32.068599]

%E[V_D]
%y_11 = [62.539451	62.567723	62.318268	62.42508	62.719108]
%y_12 = [62.511168	62.364412	62.164701	61.867249	61.833259]
%y_13 = [66.916807	67.124836	67.084114	67.105054	67.001801]
%y_14 = [66.974808	66.52422	66.116281	65.828139	65.722352]
%y_15 = [72.174265	72.194718	72.278713	72.223189	71.996613]
%y_16 = [71.564619	71.045181	70.489232	70.594657	70.315268]

i = i+1;
figure(i)

semilogx(x_label,y_11,'-d', 'MarkerSize',8, 'LineWidth',1.1,'Color',[0 0 1])
hold on
semilogx(x_label,y_12,'--s', 'MarkerSize',8, 'LineWidth',1.1,'Color',[1 0 0])
hold on
semilogx(x_label,y_13,'-d', 'MarkerSize',8, 'LineWidth',1.1,'Color',[0 0 1])
hold on
semilogx(x_label,y_14,'--s', 'MarkerSize',8, 'LineWidth',1.1,'Color',[1 0 0])
hold on
semilogx(x_label,y_15,'-d', 'MarkerSize',8, 'LineWidth',1.1,'Color',[0 0 1])
hold on
semilogx(x_label,y_16,'--s', 'MarkerSize',8, 'LineWidth',1.1,'Color',[1 0 0])
hold on


ylabel('P_{miss}')
%ylabel('E[V_0]: MB')
%ylabel('E[V_D]: MB')
xlabel('E[t_2] (Unit: E[t_1])')

xticklabels({'0.5',	'1',	'2',	'4',	'8'});
												
xlim([0.5, 8]);

%xticklabels({'0',	'1',	'2',	'3',	'4','5',	'6',	'7',	'8',	'9',	'10',	'11',	'12',	'13',	'14',	'15',	'16',	'17'	,'18'	,'20'	,'21'	,'22',	'23',	'24',	'26'});
set(gca, 'XTick', x_label);

 h = zeros(2, 1);
h(1) = plot(NaN,NaN,'Color',color_table(1,:),'LineStyle',line_style_table(:,1), 'Marker', marker_table(:,1),'MarkerSize',8, 'LineWidth',1.1);
h(2) = plot(NaN,NaN,'Color',color_table(2,:),'LineStyle',line_style_table(:,2), 'Marker', marker_table(:,2),'MarkerSize',8, 'LineWidth',1.1);
legend(h, 'Constant Bandwidth','Multiple Bandwidth');


hold off;
grid on;